/* Experimental reference values from Review of Particle Properties 2025. */

#ifndef _PDG_2025_H_
#define _PDG_2025_H_

/* Fermi decay constant. Table 1 and equation (10.8) of April 2024 RPP. 
   But note that we decrease it by a factor of (3/10) Mmu^2/MW^2, because
   we include the factor of (1 + (3/5) Mmu^2/MW^2) in the defining
   proportionality between 1/tau_mu and GF^2.
*/
SMDR_REAL SMDR_GFermi_EXPT =     0.000011663782;
SMDR_REAL SMDR_GFermi_EXPT_UNC = 0.000000000006;

/* Fine structure constant. Equation (10.11) of April 2024 RPP,
   differs from Table 1 because of updated data. */
SMDR_REAL SMDR_alpha_EXPT =     0.00729735256428;
SMDR_REAL SMDR_alpha_EXPT_UNC = 0.00000000000043;

/* MSbar at Q=MZ, top decoupled. Equation (9.25) of August 2023 RPP. */
SMDR_REAL SMDR_alphaS_MZ_EXPT =     0.1180;
SMDR_REAL SMDR_alphaS_MZ_EXPT_UNC = 0.0009;

/* MSbar at Q=MZ, top decoupled. Table 10.2 of April 2024 RPP, line 2 */
SMDR_REAL SMDR_s2W_MZ_EXPT =     0.23129;
SMDR_REAL SMDR_s2W_MZ_EXPT_UNC = 0.00004;

/* MSbar at Q=MZ, top decoupled. From 1/(127.930 +- 0.008),
   Section 10.2.2 of April 2024 RPP, two lines before equation (10.12). */
SMDR_REAL SMDR_alpha_MZ_EXPT =     0.00781677;
SMDR_REAL SMDR_alpha_MZ_EXPT_UNC = 0.00000049;

/* Hadronic contribution to \alpha. Section 10.2.2 of April 2024 RPP, line
   after equation (10.12). */
SMDR_REAL SMDR_Delta_alpha_had_5_MZ_EXPT =     0.02783;
SMDR_REAL SMDR_Delta_alpha_had_5_MZ_EXPT_UNC = 0.00006;

/* Top-quark pole mass (from cross-section measurements). June 2025 pdgLive. */
SMDR_REAL SMDR_Mt_EXPT =   172.4;
SMDR_REAL SMDR_Mt_EXPT_UNC = 0.7;

/* Higgs boson mass. June 2025 pdgLive. */
SMDR_REAL SMDR_Mh_EXPT =   125.20;
SMDR_REAL SMDR_Mh_EXPT_UNC = 0.11;

/* Z-boson PDG convention mass. We deviate from PDG by using only LEP data */
SMDR_REAL SMDR_MZ_EXPT =    91.1876;
SMDR_REAL SMDR_MZ_EXPT_UNC = 0.0021;

/* W-boson PDG convention mass. June 2025 pdgLive. Excludes CDF. */
SMDR_REAL SMDR_MW_EXPT =    80.3692;
SMDR_REAL SMDR_MW_EXPT_UNC = 0.0133;

/* Bottom-quark MSbar mass evaluated at itself. June 2025 pdgLive */
SMDR_REAL SMDR_mbmb_EXPT =        4.183;
SMDR_REAL SMDR_mbmb_EXPT_UNC_hi = 0.004;
SMDR_REAL SMDR_mbmb_EXPT_UNC_lo = 0.004;

/* Charm-quark MSbar mass evaluated at itself. June 2025 pdgLive */
SMDR_REAL SMDR_mcmc_EXPT =        1.2730;
SMDR_REAL SMDR_mcmc_EXPT_UNC_hi = 0.0028;
SMDR_REAL SMDR_mcmc_EXPT_UNC_lo = 0.0028;

/* Strange-quark MSbar mass evaluated at 2 GeV. June 2025 pdgLive */
SMDR_REAL SMDR_ms_2GeV_EXPT =        0.0935;
SMDR_REAL SMDR_ms_2GeV_EXPT_UNC_hi = 0.0005;
SMDR_REAL SMDR_ms_2GeV_EXPT_UNC_lo = 0.0005;

/* Up-quark MSbar mass evaluated at 2 GeV. June 2025 pdgLive */
SMDR_REAL SMDR_mu_2GeV_EXPT =        0.00216;
SMDR_REAL SMDR_mu_2GeV_EXPT_UNC_hi = 0.00004;
SMDR_REAL SMDR_mu_2GeV_EXPT_UNC_lo = 0.00004;

/* Down-quark MSbar mass evaluated at 2 GeV. June 2025 pdgLive */
SMDR_REAL SMDR_md_2GeV_EXPT =        0.00470;
SMDR_REAL SMDR_md_2GeV_EXPT_UNC_hi = 0.00004;
SMDR_REAL SMDR_md_2GeV_EXPT_UNC_lo = 0.00004;

/* Tau lepton pole mass. June 2025 pdgLive */
SMDR_REAL SMDR_Mtau_EXPT =     1.77693;
SMDR_REAL SMDR_Mtau_EXPT_UNC = 0.00009;

/* Muon pole mass. June 2025 pdgLive */
SMDR_REAL SMDR_Mmuon_EXPT =     0.1056583755;
SMDR_REAL SMDR_Mmuon_EXPT_UNC = 0.0000000023;

/* Electron pole mass. June 2025 pdfLive */
SMDR_REAL SMDR_Melectron_EXPT =     0.00051099895000;
SMDR_REAL SMDR_Melectron_EXPT_UNC = 0.00000000000015;

#endif
