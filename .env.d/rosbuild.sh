#!/usr/bin/env bash
## indigo_parent
mkdir -p ${HOME}/ros/indigo_parent/src
cd ${HOME}/ros/indigo_parent
catkin init
cp ${CI_SOURCE_PATH}/.env.d/.rosinstall ${HOME}/ros/indigo_parent/src/
cd ${HOME}/ros/indigo_parent/src
wstool update
cd ..
rosdep install --from-paths src --ignore-src -r
cd ${HOME}/ros/indigo_parent/src/openrtm_aist/build
bash pkg_install_debianSarge.sh
cd ${HOME}/ros/indigo_parent
catkin build -ci
source $HOME/ros/indigo_parent/devel/setup.bash

sudo updatedb
cd ${CI_SOURCE_PATH}

echo "-------------------"
echo "current directory"
echo "$(pwd)"
echo "-------------------"



