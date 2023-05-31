# G4VoxelPhantom

## ⭐ About this project
* This project is modified from ICRP110 example that used voxel phantom type (in ICRP 110 report).
* The below table summarises the features of male and female phantoms

|Features|AM|AF|
|--------|--|--|
|Height(m)| 1.76 | 1.63|
|Mass(kg)| 73.0 | 60.0 |
|Slice thickness(mm)|8.0|4.84|
|Pixel(in XY) resolution(mm)|2.173|1.775|
|Number of voxels along X(columns)|254|299|
|Number of voxels along Y(rows)|127|137|
|Number of slices (along Z)|222|348|



## 🔧 Requirements
* Ubuntu 20.04/Win 11 (Tested)
* Geant4.10.07 (Tested)
* ICRPdata package

#### a) Pre-Packages installation
- Open Ubuntu Terminal and type the following commands to update Ubuntu system.
    ```c++
    $ sudo apt-get update && sudo apt-get upgrade
    ```

- Installing pre-package using the following commands
    ```c++
    $ sudo apt-get install build-essential apt-file gcc g++ autoconf automake automake1.11 tcl8.6-dev tk8.6-dev libglu1-mesa-dev libgl1-mesa-dev libxt-dev libxmu-dev libglew-dev libglw1-mesa-dev gfortran inventor-dev libxaw7-dev freeglut3-dev libxerces-c-dev libxmltok1-dev qt5-default libxi-dev libclutter-gtk-1.0-0 cmake libxmlrpc-core-c3-dev tclxml tclxml-dev libexpat1-dev libgtk2.0-dev libxpm-dev x11proto-gl-dev x11proto-input-dev -y
    sudo apt-get install dpkg-dev cmake g++ gcc binutils libx11-dev libxpm-dev libxft-dev libxext-dev python libssl-dev gfortran libpcre3-dev xlibmesa-glu-dev libglew1.5-dev libftgl-dev libmysqlclient-dev libfftw3-dev libcfitsio-dev graphviz-dev libavahi-compat-libdnssd-dev libldap2-dev python-dev libxml2-dev libkrb5-dev libgsl0-dev qtwebengine5-dev
    ```

#### b) Geant4 installation
- I assumed that I want to install Geant4 in path ../Software/
- Create a new "Geant4" inside "Softwares" folder 
- Create 2 new folders named "build" and "install" inside "Geant4" folder.
- Copy Geant4 source code that downloaded from Geant4 Homepage to "Geant4" folder and rename to "source".
- Download all data files and extract to "data" folder that created inside "Geant4" folder.
- We will have 4 folders

    ../Softwares/Geant4/\
    ├── build\
    ├── data\
    ├── install\
    └── source

- Let open Terminal in "build" folder and type
    ```c++
    $ cmake -DGEANT4_INSTALL_DATADIR=../data \
    -DGEANT4_USE_GDML=ON \
    -DGEANT4_USE_HDF5=OFF \
    -DGEANT4_USE_OPENGL_X11=ON \
    -DGEANT4_USE_QT=ON \
    -DGEANT4_BUILD_MULTITHREADED=ON \ 
    -DCMAKE_INSTALL_PREFIX=../install \
    ../source
    $ make -j4
    $ sudo make install
    ```
#### c) Environment variables
- Add "geant4.sh" and "geant4make.sh" to at the end of file "/home/user_name/.bashrc", for example
    ```c++
    source "/home/hungbt/Softwares/Geant4/install/bin/geant4.sh"
    source "/home/hungbt/Softwares/Geant4/install/share/Geant4-10.7.4/geant4make/geant4make.sh"
    ```

#### d) Download ICRP dataset

## 🏃‍♂️ How to run
- Create a new folder to build example. For example, I created "bld" folder.
    ```c++
    cd G4IAEApsf-Reader
    mkdir bld
    cd bld
    ```
- Build
    ```c++
    cmake ..
    make -j4
    ```
- Run example in interactive mode
    ```c++
    ./SimApp
    ```
- Run example in batch mode
    ```c++
    ./SimApp run.mac
    ```
- You can select phantom type and sex by using following commands

|Command|Variable|Explain|
|-|-|-|
|**/phantom/setPhantomSex**|(1) **male** or (2) **female**||
|**/phantom/setPhantomSection**|(1) **head**, (2) **trunk** or (3) **full**||



## 📒 References
1) [Capote, R., Jeraj, R., Ma, C. M., Rogers, D. W., Sánchez-Doblado, F., Sempau, J., ... & Siebers, J. V. (2006). Phase-space database for external beam radiotherapy. Summary report of a consultants' meeting.](https://inis.iaea.org/collection/NCLCollectionStore/_Public/37/073/37073778.pdf?r=1)
2) [Cortés-Giraldo, M. A., Quesada, J. M., Gallardo, M. I., & Capote, R. (2009). Geant4 interface to work with IAEA phase-space files.](https://www-nds.iaea.org/phsp/Geant4/G4IAEAphsp_HowTo.pdf)
## 🚀 About Me
**Bùi Tiến Hưng**

Master of Science in Nuclear Engineering.

Nuclear Engineering Lab, Hanoi University of Science and Technology (HUST).

Department of Planning and R&D Management, Vietnam Atomic Energy Institute (VINATOM).

**Interestet Fields**

Medical physics, Monte-Carlo simulation, Machine learning.
 
buitienhung@vinatom.gov.vn\
hungbt1908@gmail.com

Vietnam Atomic Energy Institute, No 59 Ly Thuong Kiet stree, Hoan Kiem district, Hanoi, Vietnam. 