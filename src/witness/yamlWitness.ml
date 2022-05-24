open Analyses

let uuid_random_state = Random.State.make_self_init ()

module Make
    (Spec : Spec)
    (EQSys : GlobConstrSys with module LVar = VarF (Spec.C)
                        and module GVar = GVarF (Spec.V)
                        and module D = Spec.D
                        and module G = Spec.G)
    (LHT : BatHashtbl.S with type key = EQSys.LVar.t)
    (GHT : BatHashtbl.S with type key = EQSys.GVar.t) =
struct

  module NH = BatHashtbl.Make (Node)

  (* copied from Constraints.CompareNode *)
  let join_contexts (lh: Spec.D.t LHT.t): Spec.D.t NH.t =
    let nh = NH.create 113 in
    LHT.iter (fun (n, _) d ->
        let d' = try Spec.D.join (NH.find nh n) d with Not_found -> d in
        NH.replace nh n d'
      ) lh;
    nh

  let write lh gh =
    let yaml_creation_time = `String (TimeUtil.iso8601_now ()) in
    let yaml_producer = `O [
        ("name", `String "Goblint");
        ("version", `String Version.goblint);
        (* TODO: configuration *)
        (* TODO: command_line *)
        (* TODO: description *)
      ]
    in
    let files = GobConfig.get_string_list "files" in
    let sha256_file f = Sha256.(to_hex (file f)) in
    let sha256_file_cache = BatCache.make_ht ~gen:sha256_file ~init_size:5 in
    let sha256_file = sha256_file_cache.get in
    let yaml_task = `O [
        ("input_files", `A (List.map Yaml.Util.string files));
        ("input_file_hashes", `O (List.map (fun file ->
            (file, `String (sha256_file file))
          ) files));
        (* TODO: specification *)
        (* TODO: data_model *)
        ("language", `String "C");
      ]
    in

    let nh = join_contexts lh in

    let yaml_entries = NH.fold (fun n local acc ->
        let context: Invariant.context = {
            scope=Node.find_fundec n;
            i = -1;
            lval=None;
            offset=Cil.NoOffset;
            deref_invariant=(fun _ _ _ -> Invariant.none) (* TODO: should throw instead? *)
          }
        in
        match Spec.D.invariant context local with
        | Some inv ->
          let inv = InvariantCil.exp_replace_original_name inv in
          let loc = Node.location n in
          let uuid = Uuidm.v4_gen uuid_random_state () in
          let entry = `O [
              ("entry_type", `String "loop_invariant");
              ("metadata", `O [
                  ("format_version", `String "0.1");
                  ("uuid", `String (Uuidm.to_string uuid));
                  ("creation_time", yaml_creation_time);
                  ("producer", yaml_producer);
                  ("task", yaml_task);
                ]);
              ("location", `O [
                  ("file_name", `String loc.file);
                  ("file_hash", `String (sha256_file loc.file));
                  ("line", `Float (float_of_int loc.line));
                  ("column", `Float (float_of_int (loc.column - 1)));
                  ("function", `String (Node.find_fundec n).svar.vname);
                ]);
              ("loop_invariant", `O [
                  ("string", `String (CilType.Exp.show inv));
                  ("type", `String "assertion");
                  ("format", `String "C");
                ]);
            ]
          in
          entry :: acc
        | None ->
          acc
      ) nh []
    in

    let yaml = `A yaml_entries in
    Yaml_unix.to_file_exn (Fpath.v (GobConfig.get_string "witness.yaml.path")) yaml
end
