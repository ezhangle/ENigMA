// *****************************************************************************
// <ProjectName> ENigMA </ProjectName>
// <Description> Extended Numerical Multiphysics Analysis </Description>
// <HeadURL> $HeadURL$ </HeadURL>
// <LastChangedDate> $LastChangedDate$ </LastChangedDate>
// <LastChangedRevision> $LastChangedRevision$ </LastChangedRevision>
// <Author> Billy Araujo </Author>
// <Copyright> Copyright (c) 2012, All Rights Reserved </Copyright>
// *****************************************************************************

#include "gtest/gtest.h"

#include "TypeDef.hpp"

#include "MshMesh.hpp"

using namespace ENigMA::mesh;

class CTestMshMesh : public ::testing::Test {
protected:

    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

};

TEST_F(CTestMshMesh, set) {

    CMshMesh<decimal> aMesh;

    // Data:
    // Start Nodes
    // index  id x     y     z
    // 0      3  0.0   0.0   0.0
    // 1      5  0.25  0.0   0.0
    // 2      6  0.75  0.0   0.0
    // 3      7  1.0   0.0   0.0

    CMshNode<decimal> aNode1;
    aNode1 << 0.0, 0.0, 0.0;
    aMesh.addNode(3, aNode1);

    CMshNode<decimal> aNode2;
    aNode2 << 0.25, 0.0, 0.0;
    aMesh.addNode(5, aNode2);

    CMshNode<decimal> aNode3;
    aNode3 << 0.75, 0.0, 0.0;
    aMesh.addNode(6, aNode3);

    CMshNode<decimal> aNode4;
    aNode4 << 1.0, 0.0, 0.0;
    aMesh.addNode(7, aNode4);

    // Data:
    // Start Elements
    // index  id node1 node2
    // 0      1  3     5
    // 1      2  5     6
    // 2      3  6     7

    CMshElement<decimal> anElement1;
    anElement1.addNodeId(3);
    anElement1.addNodeId(5);
    aMesh.addElement(1, anElement1);

    CMshElement<decimal> anElement2;
    anElement2.addNodeId(5);
    anElement2.addNodeId(6);
    aMesh.addElement(2, anElement2);

    CMshElement<decimal> anElement3;
    anElement3.addNodeId(6);
    anElement3.addNodeId(7);
    aMesh.addElement(3, anElement3);

    EXPECT_EQ(4, aMesh.nbNodes());

    EXPECT_EQ(2, aMesh.element(3).nbNodeIds());

    Integer aNodeId1 = aMesh.element(3).nodeId(0);  // 6
    Integer aNodeId2 = aMesh.element(3).nodeId(1);  // 7

    EXPECT_EQ(0.75, aMesh.node(aNodeId1).x());
    EXPECT_EQ(1.0 , aMesh.node(aNodeId2).x());

}

TEST_F(CTestMshMesh, add) {

    // Mesh 1
    CMshMesh<decimal> aMesh1;

    CMshNode<decimal> aNode1;
    aNode1 << 0.0, 0.0, 0.0;
    aMesh1.addNode(1, aNode1);

    CMshNode<decimal> aNode2;
    aNode2 << 1.0, 0.0, 0.0;
    aMesh1.addNode(2, aNode2);

    CMshNode<decimal> aNode3;
    aNode3 << 1.0, 1.0, 0.0;
    aMesh1.addNode(3, aNode3);

    CMshNode<decimal> aNode4;
    aNode4 << 0.0, 1.0, 0.0;
    aMesh1.addNode(4, aNode4);

    CMshElement<decimal> anElement1;
    anElement1.addNodeId(1);
    anElement1.addNodeId(2);
    anElement1.addNodeId(4);
    aMesh1.addElement(1, anElement1);

    CMshElement<decimal> anElement2;
    anElement2.addNodeId(2);
    anElement2.addNodeId(3);
    anElement2.addNodeId(4);
    aMesh1.addElement(2, anElement2);

    // Mesh 2
    CMshMesh<decimal> aMesh2;

    CMshNode<decimal> aNode5;
    aNode5 << 1.0, 0.0, 0.0;
    aMesh2.addNode(1, aNode5);

    CMshNode<decimal> aNode6;
    aNode6 << 2.0, 0.0, 0.0;
    aMesh2.addNode(2, aNode6);

    CMshNode<decimal> aNode7;
    aNode7 << 2.0, 1.0, 0.0;
    aMesh2.addNode(3, aNode7);

    CMshNode<decimal> aNode8;
    aNode8 << 1.0, 1.0, 0.0;
    aMesh2.addNode(4, aNode8);

    CMshElement<decimal> anElement3;
    anElement3.addNodeId(1);
    anElement3.addNodeId(2);
    anElement3.addNodeId(4);
    aMesh2.addElement(1, anElement3);

    CMshElement<decimal> anElement4;
    anElement4.addNodeId(2);
    anElement4.addNodeId(3);
    anElement4.addNodeId(4);
    aMesh2.addElement(2, anElement4);

    // Mesh
    CMshMesh<decimal> aMesh;

    aMesh.addMesh(aMesh1);
    aMesh.addMesh(aMesh2);

    EXPECT_EQ(8, aMesh.nbNodes());
    EXPECT_EQ(4, aMesh.nbElements());

}

TEST_F(CTestMshMesh, addMesh) {

    // Mesh 1
    CMshMesh<decimal> aMesh1;

    CMshNode<decimal> aNode1;
    aNode1 << 0.0, 0.0, 0.0;
    aMesh1.addNode(1, aNode1);

    CMshNode<decimal> aNode2;
    aNode2 << 1.0, 0.0, 0.0;
    aMesh1.addNode(2, aNode2);

    CMshNode<decimal> aNode3;
    aNode3 << 1.0, 1.0, 0.0;
    aMesh1.addNode(3, aNode3);

    CMshNode<decimal> aNode4;
    aNode4 << 0.0, 1.0, 0.0;
    aMesh1.addNode(4, aNode4);

    CMshElement<decimal> anElement1;
    anElement1.addNodeId(1);
    anElement1.addNodeId(2);
    anElement1.addNodeId(4);
    aMesh1.addElement(1, anElement1);

    CMshElement<decimal> anElement2;
    anElement2.addNodeId(2);
    anElement2.addNodeId(3);
    anElement2.addNodeId(4);
    aMesh1.addElement(2, anElement2);

    // Mesh 2
    CMshMesh<decimal> aMesh2;

    CMshNode<decimal> aNode5;
    aNode5 << 1.0, 0.0, 0.0;
    aMesh2.addNode(1, aNode5);

    CMshNode<decimal> aNode6;
    aNode6 << 2.0, 0.0, 0.0;
    aMesh2.addNode(2, aNode6);

    CMshNode<decimal> aNode7;
    aNode7 << 2.0, 1.0, 0.0;
    aMesh2.addNode(3, aNode7);

    CMshNode<decimal> aNode8;
    aNode8 << 1.0, 1.0, 0.0;
    aMesh2.addNode(4, aNode8);

    CMshElement<decimal> anElement3;
    anElement3.addNodeId(1);
    anElement3.addNodeId(2);
    anElement3.addNodeId(4);
    aMesh2.addElement(1, anElement3);

    CMshElement<decimal> anElement4;
    anElement4.addNodeId(2);
    anElement4.addNodeId(3);
    anElement4.addNodeId(4);
    aMesh2.addElement(2, anElement4);

    // Mesh
    CMshMesh<decimal> aMesh;

    aMesh.addMesh(aMesh1);
    aMesh.addMesh(aMesh2);

    EXPECT_EQ(8, aMesh.nbNodes());
    EXPECT_EQ(4, aMesh.nbElements());

    // Merge
    aMesh.mergeNodes(0.01);

    EXPECT_EQ(6, aMesh.nbNodes());
    EXPECT_EQ(4, aMesh.nbElements());

    EXPECT_EQ(1, aMesh.element(0).nodeId(1));
    EXPECT_EQ(2, aMesh.element(1).nodeId(1));

    EXPECT_EQ(1, aMesh.element(2).nodeId(0));
    EXPECT_EQ(2, aMesh.element(2).nodeId(2));
    
    EXPECT_EQ(2, aMesh.element(3).nodeId(2));

    EXPECT_EQ(4, aMesh.nodeIndex(5));
    EXPECT_EQ(5, aMesh.nodeIndex(6));

}