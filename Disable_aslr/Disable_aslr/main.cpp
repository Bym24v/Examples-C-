#include <Windows.h>
#include <ImageHlp.h>

#pragma comment(lib, "ImageHlp.lib")

bool Disable_ASLR_DEP(LPCSTR path, bool activate)
{
	LOADED_IMAGE PE;

	if (MapAndLoad(path, 0, &PE, 0, 0))
	{
		if (activate) {
			PE.FileHeader->OptionalHeader.DllCharacteristics = IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE | IMAGE_DLLCHARACTERISTICS_NX_COMPAT;
		}
		else { 
			PE.FileHeader->OptionalHeader.DllCharacteristics = NULL;
		}

		UnMapAndLoad(&PE);

		return true;
	}
	return false;
}

int main(int argc, char *argv[])
{	
	Disable_ASLR_DEP("target.exe", false);
}