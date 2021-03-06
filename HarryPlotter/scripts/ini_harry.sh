#!/bin/bash
# This file might be merged with a general ini script

# This line fixes a bug in CMSSW6. The dateutils are not present there. This uses the dateutils from python 2.6
export PYTHONPATH=$PYTHONPATH:${CMSSW_RELEASE_BASE}/../../../../slc5_amd64_gcc462/external/py2-matplotlib/1.0.1/lib/python2.6/site-packages/

#add harry to PATH
export PATH=$CMSSW_BASE/src/HarryPlotter/Plotting/scripts:$PATH

# Use this to open a root file directly in the TBrowser
rot()
{
    root -l $@ ${CMSSW_BASE}/src/HarryPlotter/Utility/scripts/tBrowser.C
}
