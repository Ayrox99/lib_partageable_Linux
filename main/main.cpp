
#include <iostream>
#include "Composant1.h"
#include "Composant2.h"
#include <dlfcn.h>
using namespace std;

int main(int argc, char* argv[])
{
    void* handle1;
    void* handle2;
    int (*composant1)(int, int);
    int (*composant2)(int, int);
    char* error;
    char* (*getComposant1Version)();

    handle1 = dlopen(argv[1], RTLD_LAZY);
    if (!handle1) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    handle2 = dlopen(argv[2], RTLD_LAZY);
    if (!handle2) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();    /* Clear any existing error */

    composant1 = (int (*)(int, int)) dlsym(handle1, "_Z10composant1ii");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    composant2 = (int (*)(int, int)) dlsym(handle2, "_Z10composant2ii");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

	int data1=3;
	int data2=5;

	int valeur1;
	int valeur2;
	
	valeur1=composant1(data1,data2);
	valeur2=composant2(data1,data2);
    cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2;

    getComposant1Version = (char* (*)()) dlsym(handle1, "_Z20getComposant1Versionv");
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
    cout << getComposant1Version();

    dlclose(handle1);
    dlclose(handle2);
    exit(EXIT_SUCCESS);
}
