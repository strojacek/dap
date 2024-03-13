
// Generated from Scene.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "SceneParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SceneParser.
 */
class  SceneVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SceneParser.
   */
    virtual std::any visitFile(SceneParser::FileContext *context) = 0;

    virtual std::any visitName(SceneParser::NameContext *context) = 0;

    virtual std::any visitAction(SceneParser::ActionContext *context) = 0;

    virtual std::any visitSize(SceneParser::SizeContext *context) = 0;

    virtual std::any visitShape(SceneParser::ShapeContext *context) = 0;

    virtual std::any visitColor(SceneParser::ColorContext *context) = 0;

    virtual std::any visitPosition(SceneParser::PositionContext *context) = 0;


};

