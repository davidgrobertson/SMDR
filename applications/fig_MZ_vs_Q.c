/* 
   Calculates the physical mass of the Z boson as a function of the
   MSbar renormalization scale Q at which it is computed, in various
   approximations, using the results in 1505.04833. The input
   parameters are obtained from the file "ReferenceModel.dat" unless a
   different file is specified using the "-i" option; see below. 

   This program produces by default the output file "FIG_MZ_vs_Q.dat",
   with data in 18 columns:

   1  Q                  (MSbar renormalization scale)
   2  MZ_pole            (loopOrder = 0, tree-level)
   3  MZ_pole            (loopOrder = 1, 1-loop)
   4  MZ_BreitWigner     (loopOrder = 1, 1-loop)
   5  GammaZ_pole        (loopOrder = 1, 1-loop)
   6  GammaZ_BreitWigner (loopOrder = 1, 1-loop)
   7  MZ_pole            (loopOrder = 1.5, 1-loop plus 2-loop QCD)
   8  MZ_BreitWigner     (loopOrder = 1.5, 1-loop plus 2-loop QCD)
   9  GammaZ_pole        (loopOrder = 1.5, 1-loop plus 2-loop QCD)
   10 GammaZ_BreitWigner (loopOrder = 1.5, 1-loop plus 2-loop QCD)
   11 MZ_pole            (loopOrder = 2, full 2-loop)
   12 MZ_BreitWigner     (loopOrder = 2, full 2-loop)
   13 GammaZ_pole        (loopOrder = 2, full 2-loop)
   14 GammaZ_BreitWigner (loopOrder = 2, full 2-loop)
   15 MZ_pole            (loopOrder = 2.5, full 2-loop plus 3-loop QCD)
   16 MZ_BreitWigner     (loopOrder = 2.5, full 2-loop plus 3-loop QCD)
   17 GammaZ_pole        (loopOrder = 2.5, full 2-loop plus 3-loop QCD)
   18 GammaZ_BreitWigner (loopOrder = 2.5, full 2-loop plus 3-loop QCD)
 
   where the complex pole squared mass is denoted:

   s_pole = MZ_pole^2 - i GammaZ_pole MZ_pole.

   Note that the Breit-Wigner mass reported by experimentalists is
   related by

   MZ_BreitWigner^2 = MZ_pole^2 + GammaZ_pole^2

   so that MZ_BreitWigner is approximately 34 MeV larger than MZ.

   In the paper: arXiv:1907.02500
   Standard Model parameters in the tadpole-free pure MSbar scheme
   by Stephen P. Martin and David G. Robertson,
   Figure 4.1c graphs columns 4, 8, 12, and 16 as a function of column 1.

   The program takes two optional command line arguments:

   -i <input_filename>    Reads model data from <input_filename>; if 
                          not specified, data are read from the file
                          ReferenceModel.dat.

   -o <output_filename>   Writes output data to <output_filename>; if
                          not specified, the results appear in
                          "FIG_MZ_vs_Q.dat".

   The executable for this program is automatically created within the
   smdr directory by make. You can also compile it separately as:

   gcc -o fig_MZ_vs_Q fig_MZ_vs_Q.c -L. -lsmdr -ltsil -lm

   assuming the necessary archive files libsmdr.a and libtsil.a and
   the header file smdr.h are all in the current directory.

   Run as:

   ./fig_MZ_vs_Q 

   The running time is typically of order 30 seconds, depending on
   your hardware.
*/

#include "smdr.h"

/* These are the defaults: */
#define INFILENAME_DEF "ReferenceModel.dat"
#define OUTFILENAME_DEF "FIG_MZ_vs_Q.dat"

#define QSTART 50
#define QEND   221
#define QSTEP  2

int main (int argc, char *argv[]) 
{
  char inFileName[50], outFileName[50];
  FILE *outfile;
  SMDR_REAL Q;
  char funcname[] = "fig_MZ_vs_Q";

  /* Define arguments: */
  int nargs = 2;
  char *arglist[] = {"-i","-o"};
  char *argtype[] = {"string","string"};
  void *argvar[] = {inFileName, outFileName};

  char *columnDescriptor[] = {
    "1  Q                  (MSbar renormalization scale)",
    "2  MZ_pole            (loopOrder = 0, tree-level)",
    "3  MZ_pole            (loopOrder = 1, 1-loop)",
    "4  MZ_BreitWigner     (loopOrder = 1, 1-loop)",
    "5  GammaZ_pole        (loopOrder = 1, 1-loop)",
    "6  GammaZ_BreitWigner (loopOrder = 1, 1-loop)",
    "7  MZ_pole            (loopOrder = 1.5, 1-loop plus 2-loop QCD)",
    "8  MZ_BreitWigner     (loopOrder = 1.5, 1-loop plus 2-loop QCD)",
    "9  GammaZ_pole        (loopOrder = 1.5, 1-loop plus 2-loop QCD)",
    "10 GammaZ_BreitWigner (loopOrder = 1.5, 1-loop plus 2-loop QCD)",
    "11 MZ_pole            (loopOrder = 2, full 2-loop)",
    "12 MZ_BreitWigner     (loopOrder = 2, full 2-loop)",
    "13 GammaZ_pole        (loopOrder = 2, full 2-loop)",
    "14 GammaZ_BreitWigner (loopOrder = 2, full 2-loop)",
    "15 MZ_pole            (loopOrder = 2.5, full 2-loop plus 3-loop QCD)",
    "16 MZ_BreitWigner     (loopOrder = 2.5, full 2-loop plus 3-loop QCD)",
    "17 GammaZ_pole        (loopOrder = 2.5, full 2-loop plus 3-loop QCD)",
    "18 GammaZ_BreitWigner (loopOrder = 2.5, full 2-loop plus 3-loop QCD)",
    "",
    "In the paper: arXiv:1907.02500",
    "Standard Model parameters in the tadpole-free pure MSbar scheme",
    "by Stephen P. Martin and David G. Robertson,",
    "Figure 4.1c graphs columns 4, 8, 12, and 16 as a function of column 1."
  };
  int nDescriptors = 23;

  /* Set default values for optional args: */
  strcpy (inFileName, INFILENAME_DEF);
  strcpy (outFileName, OUTFILENAME_DEF);

  SMDR_Process_Arguments (argc, argv, nargs, arglist, argtype, argvar);

  /* Open the output file: */
  if ((outfile = fopen (outFileName, "w")) == NULL)
    SMDR_Error (funcname, "Output file cannot be opened.", 246);

  /* Print version information: */
  SMDR_Display_Version ();
  SMDR_Write_Version (outfile, "# ");

  /* Set benchmark parameters */
  SMDR_Read_MSbar_Inputs (inFileName);
  SMDR_Read_Value (inFileName, "SMDR_v_in");

  SMDR_Load_Inputs ();

  printf("\nInput MSbar parameters read from \"%s\":\n\n", inFileName);

  SMDR_Display_MSbar_Parameters ();
  SMDR_Display_v ();

  SMDR_Write_MSbar_Parameters (outfile, "# ");
  SMDR_Write_v (outfile, "# ");

  SMDR_Write_Column_Data (outfile, nDescriptors, columnDescriptor, "# ");

  /* The following shouldn't matter at all, but are run by SMDR_RGeval_SM() */
  SMDR_m2_in = SMDR_m2 = 0;
  SMDR_Lambda_in = SMDR_Lambda = 0;

  printf("\nOutput data is going into %s...\n", outFileName);

  for (Q = QSTART; Q <= QEND; Q += QSTEP) {

    SMDR_RGeval_SM (Q, 5);

    fprintf (outfile, "%.1Lf", Q);  

    SMDR_Eval_MZ_pole (-1, 0, &SMDR_MZ_pole, &SMDR_GammaZ_pole,
                              &SMDR_MZ_BreitWigner, &SMDR_GammaZ_BreitWigner);
    fprintf (outfile, "  %.8Lf", SMDR_MZ_pole);

    SMDR_Eval_MZ_pole (-1, 1, &SMDR_MZ_pole, &SMDR_GammaZ_pole,
                              &SMDR_MZ_BreitWigner, &SMDR_GammaZ_BreitWigner);
    fprintf (outfile, "  %.8Lf", SMDR_MZ_pole);
    fprintf (outfile, "  %.8Lf", SMDR_MZ_BreitWigner);
    fprintf (outfile, "  %.8Lf", SMDR_GammaZ_pole);
    fprintf (outfile, "  %.8Lf", SMDR_GammaZ_BreitWigner);

    SMDR_Eval_MZ_pole (-1, 1.5, &SMDR_MZ_pole, &SMDR_GammaZ_pole,
                                &SMDR_MZ_BreitWigner, &SMDR_GammaZ_BreitWigner);
    fprintf (outfile, "  %.8Lf", SMDR_MZ_pole);
    fprintf (outfile, "  %.8Lf", SMDR_MZ_BreitWigner);
    fprintf (outfile, "  %.8Lf", SMDR_GammaZ_pole);
    fprintf (outfile, "  %.8Lf", SMDR_GammaZ_BreitWigner);

    SMDR_Eval_MZ_pole (-1, 2, &SMDR_MZ_pole, &SMDR_GammaZ_pole,
                              &SMDR_MZ_BreitWigner, &SMDR_GammaZ_BreitWigner);
    fprintf (outfile, "  %.8Lf", SMDR_MZ_pole);
    fprintf (outfile, "  %.8Lf", SMDR_MZ_BreitWigner);
    fprintf (outfile, "  %.8Lf", SMDR_GammaZ_pole);
    fprintf (outfile, "  %.8Lf", SMDR_GammaZ_BreitWigner);

    SMDR_Eval_MZ_pole (-1, 2.5, &SMDR_MZ_pole, &SMDR_GammaZ_pole,
                                &SMDR_MZ_BreitWigner, &SMDR_GammaZ_BreitWigner);
    fprintf (outfile, "  %.8Lf", SMDR_MZ_pole);
    fprintf (outfile, "  %.8Lf", SMDR_MZ_BreitWigner);
    fprintf (outfile, "  %.8Lf", SMDR_GammaZ_pole);
    fprintf (outfile, "  %.8Lf", SMDR_GammaZ_BreitWigner);
    
    fprintf (outfile, "\n");
    fflush (outfile);
  }
  fclose (outfile);

  return 0;
}
