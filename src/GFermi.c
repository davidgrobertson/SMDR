#include "smdr_internal.h"

/* define global variables used in this file, for convenience with safety. */
#define AW SMDR_GFermi_AW
#define AZ SMDR_GFermi_AZ
#define Ah SMDR_GFermi_Ah
#define At SMDR_GFermi_At
#define Ab SMDR_GFermi_Ab
#define Atau SMDR_GFermi_Atau
#define Ihhh SMDR_GFermi_Ihhh
#define Ihtt SMDR_GFermi_Ihtt
#define I0ht SMDR_GFermi_I0ht
#define I0hW SMDR_GFermi_I0hW
#define I0hZ SMDR_GFermi_I0hZ
#define I0tW SMDR_GFermi_I0tW
#define I0tZ SMDR_GFermi_I0tZ
#define I0WZ SMDR_GFermi_I0WZ
#define IhhW SMDR_GFermi_IhhW
#define IhWW SMDR_GFermi_IhWW
#define IhWZ SMDR_GFermi_IhWZ
#define IhZZ SMDR_GFermi_IhZZ
#define IttW SMDR_GFermi_IttW
#define IttZ SMDR_GFermi_IttZ
#define IWWW SMDR_GFermi_IWWW
#define IWWZ SMDR_GFermi_IWWZ
#define IWZZ SMDR_GFermi_IWZZ

SMDR_COMPLEX AW, AZ, Ah, At, Ab, Atau; 
SMDR_COMPLEX Ihhh, Ihtt, I0ht, I0hW, I0hZ, I0tW, I0tZ, I0WZ; 
SMDR_COMPLEX IhhW, IhWW, IhWZ, IhZZ, IttW, IttZ, IWWW, IWWZ, IWZZ;

/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */
/* Returns GFermi at up to two loops. Based on Deltartilde given in
   section 3 of  arXiv:1907.02500 and the ancillary file Deltartilde.txt.
   See also Deltarbar in
   Kniehl and Veretin 1401.1844 eqs (37)-(40) and
   Kniehl, Pikelner, Veretin 1503.02138 eqs (60)-(62). Appendix A.2
   Kniehl, Pikelner, Veretin 1601.08143, file
   mr-1.3.2/mr/dr/drbar20.cpp in the computer code "mr".
 
  The argument loopOrder has allowed values:
    0    tree-level
    1    1-loop
    1.3  1-loop plus 2-loop leading order in QCD
    1.5  1-loop plus 2-loop leading order in QCD and yt
    2    Full 2-loop result
    2.3  Full 2-loop result + 3-loop leading order in QCD
    2.5  Full 2-loop result + 3-loop mixed QCD
    3    Full 2-loop result + 3-loop gaugeless limit

    If the argument Q_eval is positive, then the inputs are obtained
    by first RG running the MSbar parameters:

    Q_in, g3_in, g_in, gp_in, yt_in, ..., v_in

    to the scale Q_eval, using SMDR_RGeval_SM().

    If the argument Q_eval is negative, then the inputs are instead
    given by the current values of the MSbar parameters:

    Q, g3, g, gp, yt, ..., v.
*/

SMDR_REAL SMDR_Eval_GFermi (SMDR_REAL Q_eval, float loopOrder)
{
  SMDR_REAL Deltartilde;
  SMDR_REAL eightWm5Z2, Zm4t, hmW, hmW2, WmZ, WmZ2, hm4Z,hm4W;
  SMDR_REAL Deltartilde2EW;
  int success = 1;
  TVIL_RESULT result;

  SMDR_REAL Delta3r_a, Delta3r_b, Delta3r_c, Delta3r_d, Delta3r_e, 
            Delta3r_f, Delta3r_g, Delta3r_h, Delta3r_i, Delta3r_j;
  SMDR_REAL lnbart, lnbart2, lnbart3, lnbarh, lnbarh2, lnbarh3;
  SMDR_REAL hmt, hmtsq, hm2t, hm3t, hm4t, h2m2htp4t2;    

  SMDR_COMPLEX Hhtttht, Ghtttt, Fhhtt, Hhhthtt, Ghhhtt;
  SMDR_COMPLEX H0000ht, H000htt, H00h0tt, H00ht0t, H00htht, H00thtt, 
               H00ttht, H0hhtht, H0httth, H0tttht, G00tht, Gh000t, 
               Gh00tt, Gh0t0t, Gh0thh, Gh0ttt, Gt000h, Gt00ht, Gt0hht, 
               Gththt, Ft0hh, Fh0tt, Fh00t, FBAR00ht, FBAR0htt, Ihht;

  char funcname[] = "SMDR_Eval_GFermi";

  /* If Q_eval is negative, then we just use the current Q.
     Otherwise, we run all the parameters from Q_in to Q_eval. */
  if (Q_eval > 0) {
    SMDR_RGeval_SM (Q_eval, 5);
  }

  if ( (SMDR_FABS(loopOrder) > 0.0001) &&
       (SMDR_FABS(loopOrder-1) > 0.0001) &&
       (SMDR_FABS(loopOrder-1.3) > 0.0001) &&
       (SMDR_FABS(loopOrder-1.5) > 0.0001) &&
       (SMDR_FABS(loopOrder-2.0) > 0.0001) &&
       (SMDR_FABS(loopOrder-2.3) > 0.0001) &&
       (SMDR_FABS(loopOrder-2.5) > 0.0001) &&
       (SMDR_FABS(loopOrder-3) > 0.0001) 
     )
    SMDR_Error (funcname,
    "Invalid loop order specified, should be 0, 1, 1.3, 1.5, 2. 2.3, 2.5 or 3", 
    3);

  /* Check input parameters for sanity: */
  SMDR_Check_lambda_Range (0.05, 0.2);
  SMDR_Check_VEV_Range (199, 301);
  SMDR_Check_g3_Range (0.5, 1.5);
  SMDR_Check_g_Range (0.4, 0.8);
  SMDR_Check_gp_Range (0.25, 0.5);
  SMDR_Check_yt_Range (0.5, 1.5);
  SMDR_Check_yb_Range (0.05);
  SMDR_Check_ytau_Range (0.02);
  SMDR_Check_Q_Range (49, 501);

  SMDR_Update ();

  /* This is the contribution from 3/10 (Mmu/MW)^2. Almost negligible. */
  Deltartilde = 0.00000051862;

  if (loopOrder > 0.9999) {
    Ah = TSIL_A (h, Q2);
    AW = TSIL_A (W, Q2);
    AZ = TSIL_A (Z, Q2);
    At = TSIL_A (T, Q2);
    Ab = TSIL_A (b, Q2);
    Atau = TSIL_A (tau, Q2);

    Deltartilde += ONELOOPFACTOR * (
      3.*(yt2*At - yb2*Ab)/(T - b) + ytau2*Atau/(tau + .000000001) 
      + (3./4.) * (g2 - gp2) * (AZ - AW)/(Z-W) 
      + ((3./4.) * g2 * Ah  + 3.*(6.*k-g2) * AW)/(W-h) 
      -3.*g2/8. - gp2/8. - k + (3.*yb2)/2. + (3.*yt2)/2. + ytau2/2.); 
  }

  if (loopOrder > 1.4999) {
    Deltartilde += TWOLOOPFACTOR * g32 * yt2 * 
                   (-17. - 12.*At*At/T2 - 16.*At/T + 8.*Zeta2);
  }

  if (loopOrder > 1.9999) {
    Ihhh = TSIL_I2 (h, h, h, Q2);    
    Ihtt = TSIL_I2 (h, T, T, Q2);    
    I0ht = TSIL_I2 (0, h, T, Q2);    
    I0hW = TSIL_I2 (0, h, W, Q2);    
    I0hZ = TSIL_I2 (0, h, Z, Q2);    
    I0tW = TSIL_I2 (0, T, W, Q2);    
    I0tZ = TSIL_I2 (0, T, Z, Q2);    
    I0WZ = TSIL_I2 (0, W, Z, Q2);    
    IhhW = TSIL_I2 (h, h, W, Q2);    
    IhWW = TSIL_I2 (h, W, W, Q2);    
    IhWZ = TSIL_I2 (h, W, Z, Q2);    
    IhZZ = TSIL_I2 (h, Z, Z, Q2);    
    IttW = TSIL_I2 (T, T, W, Q2);    
    IttZ = TSIL_I2 (T, T, Z, Q2);    
    IWWW = TSIL_I2 (W, W, W, Q2);    
    IWWZ = TSIL_I2 (W, W, Z, Q2);    
    IWZZ = TSIL_I2 (W, Z, Z, Q2);    
    eightWm5Z2 = (8 * W - 5 * Z) * (8 * W - 5 * Z);
    Zm4t = Z - 4 * T;
    hmW = h - W;
    hmW2 = hmW * hmW;
    WmZ = W - Z;
    WmZ2 = WmZ * WmZ;
    hm4Z = h - 4 * Z;
    hm4W = h - 4 * W;

    #include "includes/Deltartilde2EW.c"

    Deltartilde += (TWOLOOPFACTOR/v4) * Deltartilde2EW;
  }


  /* 3-loop leading QCD */
  if (loopOrder > 2.01) {
    lnbart = At/T + 1.;
    lnbart2 = lnbart * lnbart;
    lnbart3 = lnbart2 * lnbart;

    Delta3r_a = -14.334528214470256 + 0.5501259195736423 * lnbart + 
                -19.833333333333333 * lnbart2 + 3.6666666666666667 * lnbart3;

    Delta3r_b = -0.2517396104459153 - 0.21516028843332296 * lnbart + 
                10.5 * lnbart2 + 6. * lnbart3;

    Delta3r_c = 32.09371831994012 - 9.227018310142792 * lnbart + 
                9.333333333333333 * lnbart2 - 2.6666666666666667 * lnbart3;

    Delta3r_d = -22.432626144403768;

    /* 
    printf("Deltara = %Lf\n", g32 * g32 * yt2 * 12.*Delta3r_a);
    printf("Deltarb = %Lf\n", g32 * g32 * yt2 * (16./3.) *Delta3r_b);
    printf("Deltarc = %Lf\n", g32 * g32 * yt2 * 6.* Delta3r_c);
    printf("Deltard = %Lf\n", g32 * g32 * yt2 * 2.* Delta3r_d);
    */

    Deltartilde += (THREELOOPFACTOR) * g32 * g32 * yt2 * 4. * (
            3. * Delta3r_a + 
       (4./3.) * Delta3r_b + 
       (3./2.) * Delta3r_c + 
       (1./2.) * Delta3r_d);
  }

  success = 1;

  /* 3-loop mixed QCD */
  if (loopOrder > 2.31) {

    Delta3r_e = -0.03986813369645287 - 1.9202637326070943 * lnbart + 
                7. * lnbart2 - 6.*lnbart3;

    /* 
    printf("Deltare = %Lf\n", g32 * yt2 * yt2 * 12. * Delta3r_e);
    */

    lnbarh = Ah/h + 1.;
    lnbarh2 = lnbarh * lnbarh;
    lnbarh3 = lnbarh2 * lnbarh;

    success *= TVIL_Hanalytic (0, 0, h, 0, T, T, Q2, &H00h0tt);    
    success *= TVIL_Hanalytic (0, 0, T, T, h, T, Q2, &H00ttht);    
    success *= TVIL_Hanalytic (0, T, T, T, h, T, Q2, &H0tttht);    
    success *= TVIL_Ganalytic (0, 0, T, h, T, Q2, &G00tht);    
    success *= TVIL_Ganalytic (h, 0, T, T, T, Q2, &Gh0ttt);    
    success *= TVIL_Ganalytic (T, 0, 0, h, T, Q2, &Gt00ht);    
    success *= TVIL_FBARanalytic (0, 0, h, T, Q2, &FBAR00ht);    
    success *= TVIL_FBARanalytic (0, h, T, T, Q2, &FBAR0htt);    
    success *= TVIL_Fanalytic (h, 0, T, T, Q2, &Fh0tt);    
    success *= TVIL_Fanalytic (h, 0, 0, T, Q2, &Fh00t);    
    Ihht = TSIL_I2 (h, h, T, Q2);    

    hmt = h - T;
    hmtsq = hmt * hmt;
    hm4t = h - 4. * T;
    h2 = h * h;
    h3 = h2 * h;
    h4 = h3 * h;
    T2 = T * T;
    T3 = T2 * T;
    T4 = T3 * T;
    h2m2htp4t2 = h2 - 2. * h * T + 4. * T2;

    #include "includes/Delta3r_f.c"

    /*
    printf("Deltarf = %Lf\n", g32 * yt2 * yt2 * 4. * Delta3r_f);
    */

    Deltartilde += (THREELOOPFACTOR) * g32 * yt2 * yt2 * 4. *
                   (3. * Delta3r_e + Delta3r_f);
  }

  /* 3-loop non-QCD */
  if (loopOrder > 2.51) {

    Delta3r_g = -0.125 + 0.75 * lnbart - 1.5 * lnbart2 + lnbart3;

    /*
    printf("Deltarg = %Lf\n", 27. * yt2 * yt2 * yt2 * Delta3r_g);
    */

    Deltartilde += (THREELOOPFACTOR) * yt2 * yt2 * yt2 * 27. * Delta3r_g;

    hm2t = h - 2. * T;
    hm3t = h - 3. * T;

    TVIL_Evaluate (h, T, T, T, h, T, Q2, &result);
    Hhtttht = TVIL_GetFunction (&result, "H");
    Gththt  = TVIL_GetFunction (&result, "Gwuzvy");
    Ghtttt  = TVIL_GetFunction (&result, "Guvxwz");
    Fhhtt   = TVIL_GetFunction (&result, "Fuvyz");

    TVIL_Evaluate (h, h, T, h, T, T, Q2, &result);
    Hhhthtt = TVIL_GetFunction (&result, "H");
    Ghhhtt  = TVIL_GetFunction (&result, "Gvuxwy");
    
    success *= TVIL_Hanalytic (0, 0, 0, 0, h, T, Q2, &H0000ht);    
    success *= TVIL_Hanalytic (0, 0, 0, h, T, T, Q2, &H000htt);    
    success *= TVIL_Hanalytic (0, 0, h, T, 0, T, Q2, &H00ht0t);    
    success *= TVIL_Hanalytic (0, 0, h, T, h, T, Q2, &H00htht);    
    success *= TVIL_Hanalytic (0, 0, T, h, T, T, Q2, &H00thtt);    
    success *= TVIL_Hanalytic (0, h, h, T, h, T, Q2, &H0hhtht);    
    success *= TVIL_Hanalytic (0, h, T, T, T, h, Q2, &H0httth);    
    success *= TVIL_Ganalytic (h, 0, 0, 0, T, Q2, &Gh000t);    
    success *= TVIL_Ganalytic (h, 0, T, 0, T, Q2, &Gh0t0t);    
    success *= TVIL_Ganalytic (h, 0, 0, T, T, Q2, &Gh00tt);    
    success *= TVIL_Ganalytic (h, 0, T, h, h, Q2, &Gh0thh);    
    success *= TVIL_Ganalytic (T, 0, 0, 0, h, Q2, &Gt000h);    
    success *= TVIL_Ganalytic (T, 0, h, h, T, Q2, &Gt0hht);    
    success *= TVIL_Fanalytic (T, 0, h, h, Q2, &Ft0hh);    

    #include "includes/Delta3r_h.c"

    /*
    printf("Deltarh = %Lf\n", 9. * yt2 * yt2 * yt2 * Delta3r_h);
    */

    Deltartilde += (THREELOOPFACTOR) * yt2 * yt2 * yt2 * 9. * Delta3r_h;

    #include "includes/Delta3r_i.c"

    /*
    printf("Deltari = %Lf\n", 3. * yt2 * yt2 * yt2 * Delta3r_i);
    */

    Deltartilde += (THREELOOPFACTOR) * yt2 * yt2 * yt2 * 3. * Delta3r_i;

    Delta3r_j = 46.88086739416974 + 44.75920123436201*lnbarh - 72.*lnbarh2;

    /*
    printf("Deltarj = %Lf\n\n\n", k * k * k * Delta3r_j);
    */

    Deltartilde += (THREELOOPFACTOR) * k * k * k * Delta3r_j;
  }

    /*
    printf("success = %d\n",success);
    */

  if (success != 1) 
     printf("Disaster! Some analytic function evaluation failed.\n");

  return ((1 + Deltartilde)/(SQRT2 * v2));
}

/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */
/* Returns the result for the Fermi decay constant G_Fermi as found by
   1411.7040 Degrassi, Gambino, and Giardino. Presumably should only
   be used if MZ_BW = SMDR_MZ_EXPT. Seems to be larger than the above
   G_Fermi by a factor of roughly 1.0002.
*/
SMDR_REAL SMDR_Eval_GFermi_DGG (SMDR_REAL Mtpole,
                                SMDR_REAL Mhpole,
                                SMDR_REAL MW_BW)
{
  SMDR_REAL boZ = 4.8 * 4.8/(SMDR_MZ_EXPT * SMDR_MZ_EXPT);
  SMDR_REAL boW = 4.8 * 4.8/(MW_BW * MW_BW);
  SMDR_REAL toW = (Mtpole * Mtpole)/(MW_BW * MW_BW);
  SMDR_REAL toZ = (Mtpole * Mtpole)/(SMDR_MZ_EXPT * SMDR_MZ_EXPT);
  SMDR_REAL hoW = (Mhpole * Mhpole)/(MW_BW * MW_BW);
  SMDR_REAL hoZ = (Mhpole * Mhpole)/(SMDR_MZ_EXPT * SMDR_MZ_EXPT);
  SMDR_REAL c2 = (MW_BW * MW_BW)/(SMDR_MZ_EXPT * SMDR_MZ_EXPT);
  SMDR_REAL s2, c4, chat2, chat4;
  SMDR_REAL r0DGG = -2.8472779;
  SMDR_REAL r1DGG = 1.620742;
  SMDR_REAL r2DGG = 1.773226;
  SMDR_REAL r3DGG = -0.364310;
  SMDR_REAL r4DGG = 1.137797;
  SMDR_REAL Delta_rW_1, Delta_rW_ho, result;

  /* Check sanity. */
  if ((Mtpole < 165) || (Mtpole > 180.0)) {
    printf("Mtpole out of range in SMDR_GFermi_DGG.\n");
    exit(1);
  }

  if ((Mhpole < 120.0) || (Mhpole > 130.0)) {
    printf("Mhpole out of range in SMDR_GFermi_DGG.\n");
    exit(1);
  }

  if ((MW_BW < 75.0) || (MW_BW > 85.0)) {
    printf("MW_BW out of range in SMDR_GFermi_DGG.\n");
    exit(1);
  }
 
  /* Run to Q=SMDR_MZ_EXPT, to obtain alpha_S, alpha, s2W there. */
  SMDR_RGeval_SM (SMDR_MZ_EXPT, 5);
  SMDR_alphaS_MZ = g3 * g3/(4. * PI);
  SMDR_alpha_MZ = g2 * gp2/(4. * PI * (g2 + gp2));
  SMDR_s2W_MZ = gp2/(g2 + gp2);
  chat2 = 1. - SMDR_s2W_MZ;
  chat4 = chat2 * chat2;
  s2 = 1. - c2;
  c4 = c2 * c2;
  /* c6 = c4 * c2; */

  /* Equation A.3 of 1411.7040 Degrassi, Gambino, Giardino: */
  Delta_rW_1 = SMDR_alpha_MZ/(4 * PI * SMDR_s2W_MZ) * ( 
    (1. + 8. * chat2)/(12. * c4) - (7. + 80. * chat2)/(24. * c2) 
    + 1./chat2 - 8. * chat2 + (794. - 21. * hoW + 6. * hoW * hoW)/72.
    + ( (chat2 + 8. * chat4 + 64. * c2 * chat4 - 6 * c4 * (8. * chat4 - 5.))/
        (12. * c2 * chat2 * s2)
      + (26. * c2 - hoW * hoW - 18. * (5. + hoZ) + hoW * (82. + hoZ))/
        (12. * s2 * (1. - hoW)) ) * SMDR_LOG(c2)
    + hoW * ((12. - 4. * hoW + hoW * hoW)/(12. * (1. - hoW))) * SMDR_LOG(hoZ)
    - ((12. - 4. * hoW + hoW * hoW)/12.) * TSIL_B (hoZ, c2, c2, 1)
    + ( (11. * chat2 + 1)/(3. * c2) + 4. * chat2 - (8. * chat2 + 1.)/(12. * c4)
        - 1./chat2 + 2. ) * TSIL_B (1, c2, c2, 1)
    + (4. * boW * toW - 2. * boW * boW - 3. * boW - 2. * toW * toW
      - 3. * toW - 12)/4. + 2. * SMDR_LOG(c2)
    + boW * (((boW - toW)*(boW - toW) + boW + 2. * toW)/(2. * (boW - toW))) *
      SMDR_LOG(boZ) 
    + toW * (((toW - boW)*(toW - boW) + toW + 2. * boW)/(2. * (toW - boW))) * 
      SMDR_LOG(toZ) 
    + 0.5 * ((toW - boW)*(toW - boW) + toW + boW - 2.) *
      TSIL_B (toZ, boZ, c2, 1) );

  /* Equation (31) of 1411.7040 Degrassi, Gambino, Giardino: */
  Delta_rW_ho = 0.0001 * (r0DGG 
                        + r1DGG * (SMDR_s2W_MZ/0.231 - 1.) 
                        + r2DGG * SMDR_LOG(Mtpole/173.34) 
                        + r3DGG * SMDR_LOG(Mhpole/125.15)
                        + r4DGG * (SMDR_alphaS_MZ/0.1184 - 1.));

  /* Equation (25) of 1411.7040 Degrassi, Gambino, Giardino: */
  result = SMDR_g2 * (1. + Delta_rW_1 + Delta_rW_ho)/
           (4 * SQRT2 * MW_BW * MW_BW);

  return(result);
}
