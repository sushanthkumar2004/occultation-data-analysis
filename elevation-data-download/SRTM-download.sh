#!/bin/bash
## Takes about 6 hours to finish running. 
## Obtain SRTM30 Data and remove all .html files
## Unzip all the provided files
echo Downloading SRTM30 files...
wget --mirror --convert-links --adjust-extension --page-requisites --no-parent https://srtm.kurviger.de/SRTM30/index.html
mv srtm.kurviger.de/SRTM30 SRTM30
echo Finished downloading SRTM30 files.

echo Unzipping data files...
find SRTM30 -type f -name "*.zip" -execdir unzip {} \;
echo Done unzipping data files

echo Removing uneeded files...
find SRTM30 -type f -name "*.zip" -exec rm {} \;
find SRTM30 -type f -name "*.html" -exec rm {} \;
rm -rf srtm.kurviger.de
echo Done removing uneeded files.

echo Moving files to correct destination...
for folder in SRTM30/*; do
  if [ -d "$folder" ]; then
    mv "$folder"/* "$folder"/..
    rm -rf "$folder"
  fi
done
echo Done moving files to correct destination.


echo Downloading SRTM3 files...
wget --mirror --convert-links --adjust-extension --page-requisites --no-parent https://srtm.kurviger.de/SRTM3/index.html
mv srtm.kurviger.de/SRTM3 SRTM3
echo Finished downloading SRTM3 files.

echo Unzipping data files...
find SRTM3 -type f -name "*.zip" -execdir unzip {} \;
echo Done unzipping data files

echo Removing uneeded files...
find SRTM3 -type f -name "*.zip" -exec rm {} \;
find SRTM3 -type f -name "*.html" -exec rm {} \;
rm -rf srtm.kurviger.de
echo Done removing uneeded files.

echo Moving files to correct destination...
for folder in SRTM3/*; do
  if [ -d "$folder" ]; then
    mv "$folder"/* "$folder"/..
    rm -rf "$folder"
  fi
done
echo Done moving files to correct destination.
