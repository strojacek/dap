
// Generated from Scene.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "SceneVisitor.h"


/**
 * This class provides an empty implementation of SceneVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SceneBaseVisitor : public SceneVisitor {
public:

  virtual std::any visitFile(SceneParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitName(SceneParser::NameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAction(SceneParser::ActionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSize(SceneParser::SizeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShape(SceneParser::ShapeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColor(SceneParser::ColorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPosition(SceneParser::PositionContext *ctx) override {
    return visitChildren(ctx);
  }


};

