#include <stdio.h>
#include <stdlib.h>
FILE *fp;
int main(int argc, char* argv[]){
	fp = fopen("CMakeLists.txt","w");
	if(argc <= 1) {
		printf("No project name!\n");
		return 1;
	}
	char* obj_name = argv[1];
	fprintf(fp,"cmake_minimum_required(VERSION 2.8)\n"); //first line 
	fprintf(fp,"project(%s)\n",obj_name); //Define project name
	fprintf(fp,"find_package(OpenCV REQUIRED)\nmessage(STATUS \"OpenCV library status:\")\nmessage(STATUS \"    version: ${OpenCV_VERSION}\")\nmessage(STATUS \"    libraries: ${OpenCV_LIBS}\")\nmessage(STATUS \"    include path: ${OpenCV_INCLUDE_DIRS}\")\n");
	//find package and send some massage.
	
	fprintf(fp,"include_directories(${OpenCV_INCLUDE_DIRS})\n"); //add opencv header
	fprintf(fp,"add_executable(%s %s.cpp)\n",obj_name,obj_name); //executable target built from your sources
	fprintf(fp,"target_link_libraries(%s ${OpenCV_LIBS})\n",obj_name);//link the app with the opencv libraries
	
	return 0;	 
}
