type arinc_node =
  | PC of int list  (* list of arinc task locations for each task *)

let node_compare x y = compare x y

let print doc =
  print_string @@ Pretty.sprint max_int doc

let to_str doc =
  Pretty.sprint max_int doc
let print_b bool =
  print_endline (if bool then "true" else "false"); bool

module Arinc_Node :
sig
  include Hashtbl.HashedType with type t = arinc_node
  include Set.OrderedType with type t := arinc_node
end =
struct
  type t = arinc_node
  let equal x y = x = y
  let hash x = 42 (* missing *)

  let compare = node_compare
end
