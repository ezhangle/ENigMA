
import subprocess

import ENigMA
 
edgeMesh = ENigMA.CMshMeshDouble()

node1 = ENigMA.CMshNodeDouble(0, 0, 0)
node2 = ENigMA.CMshNodeDouble(400, 0, 0)
node3 = ENigMA.CMshNodeDouble(400, 400, 0)
node4 = ENigMA.CMshNodeDouble(0, 400, 0)

edgeMesh.addNode(1, node1)
edgeMesh.addNode(2, node2)
edgeMesh.addNode(3, node3)
edgeMesh.addNode(4, node4)

element1 = ENigMA.CMshElementDouble(ENigMA.ET_BEAM)
element1.addNodeId(1)
element1.addNodeId(2)

element2 = ENigMA.CMshElementDouble(ENigMA.ET_BEAM)
element2.addNodeId(2)
element2.addNodeId(3)

element3 = ENigMA.CMshElementDouble(ENigMA.ET_BEAM)
element3.addNodeId(3)
element3.addNodeId(4)

element4 = ENigMA.CMshElementDouble(ENigMA.ET_BEAM)
element4.addNodeId(4)
element4.addNodeId(1)

edgeMesh.addElement(1, element1)
edgeMesh.addElement(2, element2)
edgeMesh.addElement(3, element3)
edgeMesh.addElement(4, element4)

quadrilateralMesher = ENigMA.CMshQuadrilateralMesherDouble()

meshSize = 20

edgeMesh.generateFaces(1E-3)
quadrilateralMesher.remesh(edgeMesh, meshSize);
quadrilateralMesher.generate(edgeMesh, 9999, meshSize, 0.1, 1E-3)

surfaceMesh = quadrilateralMesher.mesh()

print surfaceMesh.nbNodes()
print surfaceMesh.nbElements()

pdeField = ENigMA.CPdeFieldDouble()

pdeField.setMesh(surfaceMesh)

posGmsh = ENigMA.CPosGmshDouble()

posGmsh.save(pdeField, "mesh1.msh", "tris");

subprocess.call(['gmsh.exe', 'mesh1.msh'])