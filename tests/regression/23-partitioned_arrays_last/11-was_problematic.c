// PARAM: --sets solver td3 --enable ana.int.interval --enable exp.partition-arrays.enabled  --sets exp.partition-arrays.keep-expr "last"  --set ana.activated "['base','threadid','threadflag','expRelation','mallocWrapper','assert']"
int main(int argc, char **argv)
{
  int unLo;
  int sp = 1;
  int nextD[3];

  // nextD[0] = 2; // When we have this and the one in line 25 it is fine

  int x;

  while (sp > 0)
  {
    sp--;

    while (1)
    {
      if (x+1 <= 100 || x+1 > 100)
      {
        break;
      }
    }

    // If we have only this one there is a problem
    nextD[0] = 2;

    int y = 27;
 }

  assert(1 == 1); // Was reported as unreachable before
  return 0;
}
