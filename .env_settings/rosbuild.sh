#!/usr/bin/env bash
## indigo_parent
mkdir -p ${HOME}/ros/indigo_parent/src
cp ${REPOSITORY_TOP}/.env_settings/.rosinstall ${HOME}/ros/indigo_parent/src/
cd ${HOME}/ros/indigo_parent/src
wstool update
cd ${HOME}/ros/indigo_parent
catkin build -ci
source $HOME/ros/indigo_parent/devel/setup.bash

cd ${REPOSITORY_TOP}
