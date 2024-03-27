package com.jazz.core;

public class Bspline {

        public static void bsplvb(double[] t,
                                  int jhigh,
                                  int index,
                                  double x,
                                  int left,
                                  double[] biatx,
                                  int[] j,
                                  double[] deltal,
                                  double[] deltar) {

            // Local Variables
            int i, jp1;
            double saved, term;

            if (index == 1) {
                j[0] = 1;
                biatx[0] = 1.0;
                if (j[0] >= jhigh) return;
            }

            do {
                jp1 = j[0] + 1;
                deltar[j[0] - 1] = t[left + j[0] - 1] - x;
                deltal[j[0] - 1] = x - t[left - j[0]];
                saved = 0.0;

                for (i = 0; i < j[0]; i++) {
                    term = biatx[i] / (deltar[i] + deltal[jp1 - i - 2]);
                    biatx[i] = saved + deltar[i] * term;
                    saved = deltal[jp1 - i - 2] * term;
                }

                biatx[jp1 - 1] = saved;
                j[0] = jp1;

            } while (j[0] < jhigh);
        }
    }
