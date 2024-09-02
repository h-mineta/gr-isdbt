# GNU Radio - ISDB-T

## INSTALL (Debian)
```bash
sudo apt-get update && sudo apt-get full-upgrade
sudo reboot
sudo apt-get -y install soapysdr-tools gnuradio cmake libsoapysdr-dev python3-soapysdr doxygen swig libgsl-dev pybind11-dev

mkdir -p ~/workspace

# SDR Player API
# https://www.sdrplay.com/api/ から3.15をダウンロードし、RPiへ転送
cd ~/workspace
chmod +x SDRplay_RSP_API-Linux-3.15.2.run
./SDRplay_RSP_API-Linux-3.15.2.run

# 手動でSoapySDR Playビルド
cd ~/workspace
git clone https://github.com/pothosware/SoapySDRPlay.git
cd SoapySDRPlay
mkdir build
cd build
cmake ..
make -j4
sudo make install

# SoapySDRUtilで確認
cd ~
SoapySDRUtil --probe=driver="sdrplay"


# GR-ISDBT
cd ~/workspace
git clone https://github.com/h-mineta/gr-isdbt.git
cd gr-isdbt  
mkdir build
cd build
cmake -DCMAKE_SYSTEM_PROCESSOR=ARM64 ..
sudo make install

```
