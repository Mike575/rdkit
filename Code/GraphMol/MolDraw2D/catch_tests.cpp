//
//  Copyright (C) 2019 Greg Landrum
//
//   @@ All Rights Reserved @@
//  This file is part of the RDKit.
//  The contents are covered by the terms of the BSD license
//  which is included in the file license.txt, found at the root
//  of the RDKit source tree.
//
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "catch.hpp"

#include <GraphMol/RDKitBase.h>

#include <GraphMol/SmilesParse/SmilesParse.h>
#include <GraphMol/MolDraw2D/MolDraw2D.h>
#include <GraphMol/MolDraw2D/MolDraw2DSVG.h>
#include <GraphMol/MolDraw2D/MolDraw2DUtils.h>

using namespace RDKit;

TEST_CASE("prepareAndDrawMolecule", "[drawing]") {
  SECTION("basics") {
    auto m1 = "C1N[C@@H]2OCC12"_smiles;
    REQUIRE(m1);

    // we will be able to recognize that the prep worked because there
    // will be an H in the output:
    MolDraw2DSVG drawer(200, 200);
    MolDraw2DUtils::prepareAndDrawMolecule(drawer, *m1);
    drawer.finishDrawing();
    std::string text = drawer.getDrawingText();
    CHECK(text.find("<tspan>H</tspan>")!=std::string::npos);
  }
}
