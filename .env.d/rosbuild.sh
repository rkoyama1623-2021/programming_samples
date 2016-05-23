#!/usr/bin/env bash
## indigo_parent
mkdir -p ${HOME}/ros/indigo_parent/src
cd ${HOME}/ros/indigo_parent
catkin init
cp ${CI_SOURCE_PATH}/.env_settings/.rosinstall ${HOME}/ros/indigo_parent/src/
cd ${HOME}/ros/indigo_parent/src
wstool update
cd ..
rosdep install --from-paths src --ignore-src -r
cd ${HOME}/ros/indigo_parent/src/openrtm_aist/build
bash pkg_install_debianSarge.sh
cd ${HOME}/ros/indigo_parent
catkin build -ci
source $HOME/ros/indigo_parent/devel/setup.bash

cat "function catkin () {
/usr/bin/catkin ${@};
cp ${REPOSITORY_TOP}/.env_settings/.catkin /home/koyama/ros/indigo_parent/devel/.catkin;
}" >> ${HOME}/.bashrc
source ${HOME}/.bashrc
sudo updatedb
cd ${CI_SOURCE_PATH}

echo "-------------------"
echo "current directory"
echo "$(pwd)"
echo "-------------------"



