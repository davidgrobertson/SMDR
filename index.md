## [S]tandard [M]odel in [D]imensional [R]egularization

`SMDR` is a library of computer utilities, written in C, for calculations in the tadpole-free pure MSbar scheme in the Standard Model of particle physics.

The MSbar Lagrangian parameters are treated as the fundamental inputs, and calculations relating them to on-shell observable quantities are implemented in a consistent way. The Higgs vacuum expectation value (VEV) is defined as the minimum of the Landau gauge effective potential, so that tadpole diagrams vanish.

Included at present are the minimization condition for the VEV at 3-loop order with 4-loop QCD effects, the Higgs pole mass at 2-loop order with 3-loop QCD and top-quark Yukawa effects, the top-quark pole mass at 4-loop order in QCD with full 2-loop electroweak effects, the W- and Z-boson pole and Breit-Wigner masses and the Fermi decay constant at full 2-loop orders, the fine structure constant and weak mixing angle, and all known contributions to renormalization group equations and threshold matching relations for the gauge couplings, fermion masses and Yukawa couplings.

The code is written in C, and may be linked from C or C++. `SMDR` is free software, released under the [GPL](http://www.gnu.org/licenses/gpl-3.0.html).

The authors are [Stephen P. Martin](https://www.niu.edu/spmartin) and [David G. Robertson](http://faculty.otterbein.edu/drobertson). The paper announcing `SMDR` is available from the arXiv.org preprint archive as [1907.02500](https://arxiv.org/abs/1907.02500).

Click [here](https://github.com/davidgrobertson/SMDR/releases/tag/v1.1) for the latest release. Note that `SMDR` includes copies of the [`TSIL`](https://davidgrobertson.github.io/TSIL) and [`3VIL`](https://davidgrobertson.github.io/3VIL) libraries of utilities for the numerical calculation of dimensionally regularized two-loop self-energy integrals and three-loop vacuum integrals, respectively.

`SMDR` subsumes and replaces our earlier program `SMH`, which calculated the Higgs pole mass.

This material is based upon work supported by the National Science Foundation under Grant PHY-1719273. The work of DGR was supported in part by a grant from the Ohio Supercomputer Center.

Any opinions, findings, and conclusions or recommendations expressed in this material are those of the authors and do not necessarily reflect the views of the National Science Foundation. 
