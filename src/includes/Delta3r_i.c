
Delta3r_i = 0.0;

Delta3r_i += 
     555.590769471358 - (0.25*FBAR00ht)/h - (0.625*Fh00t)/h - 
     (4.625*Fh0tt)/h - (2.3958333333333335*Fhhtt)/h - (3.625*Ft0hh)/h - 
     (2.5*Gt000h)/h + (7.375*Gt00ht)/h - (8.375*Gt0hht)/h + (4.25*Gththt)/h + 
     0.5*H0000ht - 2.25*H000htt - 2.*H00htht - 2.*H00thtt + 0.5*H00ttht + 
     3.75*H0hhtht - 4.5*H0httth + 2.*Hhhthtt + 4.*Hhtttht - 
     (1.5*Fhhtt)/hm2t + (0.5*Ghtttt)/hm2t - (0.5*Gththt)/hm2t + 
     (9.*Fhhtt)/hm3t - (2.25*Ghhhtt)/hm3t + (2.25*Gththt)/hm3t + 
     (3.*Fh00t)/hm4t - (27.*Fhhtt)/hm4t + (9.*Gh00tt)/hm4t + 
     (27.*Ghhhtt)/hm4t - (1.5*Gt00ht)/hm4t + (2.25*Fh0tt*h)/hmtsq + 
0;

/*  Silly breakup of expression to avoid an annoying compiler bug. */

Delta3r_i += 
     (12.458333333333334*I0ht)/h + (4.5*I0ht)/hm4t - 
     (4.708333333333333*Ihht)/h - (25.15972222222222*Ihtt)/h - 
     (4.5*Ihtt)/hm3t - (3.*Ihtt)/hm4t + (0.875*h*Ihtt)/hmtsq - 
     363.76427610027235*lnbarh + (0.625*I0ht*lnbarh)/h - 
     (1.*Ihtt*lnbarh)/hm2t + (4.5*Ihtt*lnbarh)/hm3t + (6.*Ihtt*lnbarh)/hm4t + 
     68.09375*lnbarh2 - 56.094211325185455*lnbart - (4.5*I0ht*lnbart)/h + 
     (7.5*Ihtt*lnbart)/h + (Ihtt*lnbart)/hm2t - (2.25*Ihtt*lnbart)/hm3t - 
     (3.*Ihtt*lnbart)/hm4t + 33.15277777777778*lnbarh*lnbart - 
     9.604166666666666*lnbarh2*lnbart + 8.307291666666666*lnbart2 + 
     1.6666666666666667*lnbarh*lnbart2 + 2.3958333333333335*lnbart3 - 
     (2.375*Fh00t)/T + (5.625*Fh0tt)/T + (3.5*Fhhtt)/T + (10.96875*Ft0hh)/T + 
0;

/*  Silly breakup of expression to avoid an annoying compiler bug. */

Delta3r_i += 
     (1.625*Gh000t)/T + (3.75*Gh00tt)/T - (1.125*Gh0thh)/T - 
     (3.75*Gh0ttt)/T + (9.*Ghhhtt)/T + (4.125*Ghtttt)/T + (1.5*Gt000h)/T - 
     (5.625*Gt00ht)/T + (8.5*Gt0hht)/T - (2.2708333333333335*Gththt)/T + 
     (215.10467439481567*h)/T - (0.5*h*H0000ht)/T + (0.5*h*H000htt)/T - 
     (1.75*h*H00ht0t)/T + (0.5*h*H00htht)/T + (2.75*h*H00thtt)/T - 
     (6.75*h*H0hhtht)/T + (2.5*h*H0httth)/T + (5.25*h*Hhhthtt)/T - 
     (2.5*h*Hhtttht)/T + (2.0625*I0ht)/T + (7.6875*Ihht)/T - 
     (1.6944444444444444*Ihtt)/T - (163.1718031903799*h*lnbarh)/T - 
     (1.75*I0ht*lnbarh)/T + (10.25*Ihtt*lnbarh)/T + 
0;

/*  Silly breakup of expression to avoid an annoying compiler bug. */

Delta3r_i += 
     (30.48611111111111*h*lnbarh2)/T - (0.08333333333333333*h*lnbarh3)/T - 
     (68.92128194440019*h*lnbart)/T - (0.5*I0ht*lnbart)/T + 
     (0.8333333333333334*Ihtt*lnbart)/T + (63.25*h*lnbarh*lnbart)/T - 
     (9.25*h*lnbarh2*lnbart)/T + (10.604166666666666*h*lnbart2)/T - 
     (6.447916666666667*h*lnbarh*lnbart2)/T + (0.25*h*lnbart3)/T - 
     (28.27309285866855*T)/h - (3.5*H00ttht*T)/h + (2.25*H0httth*T)/h + 
0;

/*  Silly breakup of expression to avoid an annoying compiler bug. */

Delta3r_i += 
     (2.0416666666666665*Fh0tt*T)/h2 - (0.3958333333333333*Fhhtt*T)/h2 + 
     (0.9375*Ft0hh*T)/h2 - (1.25*Gt00ht*T)/h2 + (1.25*Gt0hht*T)/h2 - 
     (0.625*Gththt*T)/h2 + (7.618723569826261*T)/hm2t - 
     (127.12662235232028*T)/hm3t + (2175.2251396013125*T)/hm4t - 
     (4.3125*Fh0tt*T)/hmtsq - (2.3399093419163113*h*T)/hmtsq - 
     (3.4166666666666665*I0ht*T)/h2 + (0.7708333333333334*Ihht*T)/h2 + 
     (6.583333333333333*Ihtt*T)/h2 - (2.9375*Ihtt*T)/hmtsq + 
     (36.095792125113476*lnbarh*T)/h + (2.25*lnbarh*T)/hm2t + 
     (85.5*lnbarh*T)/hm3t - (1568.5651977994553*lnbarh*T)/hm4t - 
     (10.82677610027234*h*lnbarh*T)/hmtsq - (20.25*lnbarh2*T)/hm3t + 
     (312.*lnbarh2*T)/hm4t + (38.06504636541888*lnbart*T)/h + 
0;

/*  Silly breakup of expression to avoid an annoying compiler bug. */

Delta3r_i += 
     (5.*lnbart*T)/hm2t - (33.857060791730774*lnbart*T)/hm3t - 
     (131.22205483911614*lnbart*T)/hm4t + (1.2174011002723397*h*lnbart*T)/
      hmtsq + (1.25*I0ht*lnbart*T)/h2 - (1.25*Ihtt*lnbart*T)/h2 - 
     (26.833333333333332*lnbarh*lnbart*T)/h - (6.*lnbarh*lnbart*T)/hm2t + 
     (31.5*lnbarh*lnbart*T)/hm3t + (162.*lnbarh*lnbart*T)/hm4t + 
     (7.625*h*lnbarh*lnbart*T)/hmtsq + (0.3958333333333333*lnbarh2*lnbart*T)/
      h + 
0;

/*  Silly breakup of expression to avoid an annoying compiler bug. */

Delta3r_i += 
     (lnbarh2*lnbart*T)/hm2t - (3.375*lnbarh2*lnbart*T)/hm3t - 
     (48.*lnbarh2*lnbart*T)/hm4t - (20.26388888888889*lnbart2*T)/h - 
     (2.*lnbart2*T)/hm2t + (7.5*lnbart2*T)/hm4t - (0.6875*lnbart2*T)/hmt + 
     (6.3125*lnbarh*lnbart2*T)/h + (0.5*lnbarh*lnbart2*T)/hm2t - 
     (4.5*lnbarh*lnbart2*T)/hm3t + (10.5*lnbarh*lnbart2*T)/hm4t - 
     (2.25*h*lnbarh*lnbart2*T)/hmtsq + (1.7083333333333333*lnbart3*T)/h + 
0;

/*  Silly breakup of expression to avoid an annoying compiler bug. */

Delta3r_i += 
     (0.5*lnbart3*T)/hm2t + (5.25*lnbart3*T)/hm4t + 
     (0.75*h*lnbart3*T)/hmtsq + (0.25*FBAR00ht*h)/T2 - (0.6875*Fh00t*h)/T2 + 
     (4.291666666666667*Fh0tt*h)/T2 - (10.291666666666666*Fhhtt*h)/T2 - 
     (3.875*Ft0hh*h)/T2 + (4.*Gh000t*h)/T2 - (2.875*Gh00tt*h)/T2 + 
     (6.375*Gh0thh*h)/T2 - (0.25*Gh0ttt*h)/T2 - (2.625*Ghhhtt*h)/T2 - 
     (0.75*Gt000h*h)/T2 - (0.1875*Gt00ht*h)/T2 - (1.6875*Gt0hht*h)/T2 - 
     (1.8333333333333333*Gththt*h)/T2 + (35.0098140819122*h2)/T2 - 
     (0.25*H000htt*h2)/T2 - (0.5*H00ht0t*h2)/T2 + (0.75*H00thtt*h2)/T2 + 
0;

/*  Silly breakup of expression to avoid an annoying compiler bug. */

Delta3r_i += 
     (3.*H0hhtht*h2)/T2 + (0.375*H0httth*h2)/T2 - (3.*h2*Hhhthtt)/T2 - 
     (0.375*h2*Hhtttht)/T2 - (11.083333333333334*h*I0ht)/T2 - 
     (4.8125*h*Ihht)/T2 + (21.708333333333332*h*Ihtt)/T2 - 
     (33.85439148328794*h2*lnbarh)/T2 + (0.4375*h*I0ht*lnbarh)/T2 - 
     (4.708333333333333*h*Ihtt*lnbarh)/T2 + (4.90625*h2*lnbarh2)/T2 + 
     (0.041666666666666664*h2*lnbarh3)/T2 - (1.3538790248823498*h2*lnbart)/
      T2 + (2.5*h*I0ht*lnbart)/T2 - (6.583333333333333*h*Ihtt*lnbart)/T2 + 
     (2.6875*h2*lnbarh*lnbart)/T2 - (0.2916666666666667*h2*lnbarh2*lnbart)/
      T2 + (0.625*h2*lnbart2)/T2 + (3.9735317356016866*T2)/h2 + 
0;

/*  Silly breakup of expression to avoid an annoying compiler bug. */

Delta3r_i += 
     (1.25*H00ttht*T2)/h2 - (0.625*H0httth*T2)/h2 - 
     (4.363215658083688*T2)/hmtsq - (8.229166666666666*lnbarh*T2)/h2 + 
     (21.85418544218865*lnbarh*T2)/hmtsq - (4.0038273629245715*lnbart*T2)/
      h2 + (2.7083145578113488*lnbart*T2)/hmtsq + 
     (6.583333333333333*lnbarh*lnbart*T2)/h2 - (15.875*lnbarh*lnbart*T2)/
      hmtsq + (2.5208333333333335*lnbart2*T2)/h2 - 
     (1.6458333333333333*lnbarh*lnbart2*T2)/h2 + (4.3125*lnbarh*lnbart2*T2)/
      hmtsq + (0.3402777777777778*lnbart3*T2)/h2 - 
     (1.4375*lnbart3*T2)/hmtsq + (4.5625*Fh00t*h2)/T3 - (2.625*Fh0tt*h2)/T3 + 
     (2.5833333333333335*Fhhtt*h2)/T3 + (0.125*Ft0hh*h2)/T3 - 
     (1.25*Gh000t*h2)/T3 + (1.25*Gh00tt*h2)/T3 - (2.625*Gh0thh*h2)/T3 + 
0;

/*  Silly breakup of expression to avoid an annoying compiler bug. */

Delta3r_i += 
     (2.625*Ghhhtt*h2)/T3 - (0.4375*Gt0hht*h2)/T3 + 
     (1.6666666666666667*Gththt*h2)/T3 + (1.5817408981790744*h3)/T3 + 
     (3.8541666666666665*h2*I0ht)/T3 + (0.25*h2*Ihht)/T3 - 
     (3.8541666666666665*h2*Ihtt)/T3 - (0.7706085167120567*h3*lnbarh)/T3 + 
     (0.1875*h2*I0ht*lnbarh)/T3 + (2.2708333333333335*h2*Ihtt*lnbarh)/T3 + 
     (0.5104166666666666*h3*lnbarh2)/T3 - (0.041666666666666664*h3*lnbarh3)/
      T3 + (0.1612335167120566*h3*lnbart)/T3 + (0.375*Fh00t*h3)/T4 - 
     (0.3125*Fh0tt*h3)/T4 - (0.08854166666666667*h4)/T4 + 
     (0.375*h3*I0ht)/T4 - (0.3125*h3*Ihtt)/T4 + (0.046875*h4*lnbarh)/T4;
