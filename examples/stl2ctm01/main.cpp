#include<iostream>
#include"stl_reader.h"
#include <openctmpp.h>

void saveFile(CTMuint aVertCount, CTMuint aTriCount, const CTMfloat * aVertices, const CTMuint * aIndices, const char * aFileName);

int main()
{ 
  // CTMcontext context;
  CTMuint vertCount, triCount;
  const CTMuint * indices;
  const CTMfloat * vertices;

  const char* inputFileName="sample-man.stl";
  try 
  {
    stl_reader::StlMesh <float, unsigned int> mesh (inputFileName);

    // std::cout<<"num_tris: "<<mesh.num_tris()<<std::endl;
    // std::cout<<"raw_tris: "<<mesh.raw_tris()<<std::endl;
    // std::cout<<"num_vrts: "<<mesh.num_vrts()<<std::endl;
    // std::cout<<"raw_vrts: "<< mesh.raw_coords() <<std::endl;
    
    vertCount=mesh.num_vrts();
    triCount = mesh.num_tris();
    vertices=mesh.raw_coords();
    indices = mesh.raw_tris();
    
    saveFile(vertCount, triCount, vertices, indices, "result.ctm");
  }
  catch (std::exception& e) 
  {
    std::cout << e.what() << std::endl;
  }
  return 0;
}

void saveFile(CTMuint aVertCount, CTMuint aTriCount, const CTMfloat * aVertices, const CTMuint * aIndices, const char * aFileName)
{
    try 
    {
        // Create a new OpenCTM exporter object
        CTMexporter ctm;
        // Define our mesh representation to OpenCTM
        ctm.DefineMesh(aVertices, aVertCount, aIndices,
        aTriCount, NULL);
        // Save the OpenCTM file
        ctm.Save(aFileName);
    }
    catch(ctm_error &e)
    {
        std::cout << "Error: "<< e.what()<< std::endl;
    }
}