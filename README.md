# Occultation and Elevation Data Analysis
The Shuttle Radar Topography Mission (SRTM) by NASA provided worldwide 3 arcsecond resolution of the elevation around the globe. Earth 2014 and GMTED 2010 are similar global digital elevation models of the Earth at varying resolutions. The following code will download and install and cleanup the datasets required for the code to run: 
```
chmod +x EARTH2014-download.sh
chmod +x SRTM-download.sh
./EARTH2014-download.sh
./SRTM-download.sh
```
The SRTM script downloads both SRTM3 and SRTM30 datasets and takes about 6 hours to finish running, while the Earth 2014 dataset takes around 5 minutes to download. Both scripts will download to the current directory, so please make sure the directory is large enough for around 80 GB of data. 
