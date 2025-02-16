/* CDA pp. 135 - 138, 171 - 174, 176 - 177
 * Here we fit loglinear models in table 6.3 on p. 172
 */
#include <dap.h>

void main()
{
  infile("cda171.dat", " ")
    {
      char defendant[6], victim[6], penalty[4];
      double n;
      input("defendant victim penalty n");
      outset("cda171", "");
      skip(2);
      while (step())
        output();
    }

  sort("cda171", "defendant victim penalty", "");

  title("(DV, P) vs (D, V, P)");
  loglin("cda171.srt", "n defendant victim penalty",
         "victim penalty defendant", "defendant*victim penalty", "");

  sort("cda171.srt.llm", "defendant victim _type_ penalty", "");
  table("cda171.srt.llm.srt", "defendant victim", "_type_ penalty n", "s6.2 30", "");
    
  title("(DV, VP) vs (DV, P)");
  loglin("cda171.srt", "n defendant victim penalty",
         "defendant*victim penalty", "defendant*victim victim*penalty", "");
  sort("cda171.srt.llm", "defendant victim _type_ penalty", "");
  table("cda171.srt.llm.srt", "defendant victim", "_type_ penalty n", "s6.2 30", "");
  
  title("(DV, DP, VP) vs (DV, VP)");
  loglin("cda171.srt", "n defendant victim penalty",
         "defendant*victim victim*penalty",
         "defendant*victim defendant*penalty victim*penalty", "");
  sort("cda171.srt.llm", "defendant victim _type_ penalty", "");
  table("cda171.srt.llm.srt", "defendant victim", "_type_ penalty n", "s6.2 30", "");
}
