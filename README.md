![CmakeCI](https://github.com/tort-dla-psa/logicsim/workflows/CmakeCI/badge.svg?branch=master&event=push)

# logicsim
Modern c++/qt logic blocks simulator designed as a successor of famous [Logisim](http://www.cburch.com/logisim/), which I absolutely love and recommend to try.

## Prerequisites
* Qt5
* g++8 or newer
* cmake3

## Build
```bash
git clone https://github.com/tort-dla-psa/logicsim
mkdir -p logicsim/build
cd logicsim/build
cmake ..
make -j4
```
