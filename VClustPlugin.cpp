#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "VClustPlugin.h"

void VClustPlugin::input(std::string file) {
 inputfile = file;
}

void VClustPlugin::run() {
   
}

void VClustPlugin::output(std::string file) { 
	std::string command = "mkdir -p "+file+"; cd "+file+"; vsearch --cluster_size "+inputfile+" --id 0.90 --msaout MSA.tmp; awk '!a[$0]++ {of=\"./cluster-\" ++fc \".msa\"; print $0 >> of ; close(of)}' RS= ORS=\"\n\n\" MSA.tmp; rm MSA.tmp; cd ..";
 std::cout << command << std::endl;
 system(command.c_str());
}

PluginProxy<VClustPlugin> VClustPluginProxy = PluginProxy<VClustPlugin>("VClust", PluginManager::getInstance());
