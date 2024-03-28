// Generated from CommonParserRules.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class CommonParserRules extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		ABORT=1, ABEND=2, CANCEL=3, FILE=4, RETURN=5, NOLIST=6, ARRAY=7, ARRAY_NUMERIC_ELEMENTS=8, 
		ARRAY_CHARACTER_ELEMENTS=9, ARRAY_ALL_ELEMENTS=10, BY=11, GROUPFORMAT=12, 
		NOTSORTED=13, DESCENDING=14, CALL=15, DATALINES=16, CARDS=17, LINES=18, 
		DATALINES4=19, CARDS4=20, LINES4=21, END_DATALINES4=22, INFILE=23, DISK=24, 
		DUMMY=25, GTERM=26, PIPE=27, PLOTTER=28, PRINTER=29, TAPE=30, TEMP=31, 
		TERMINAL=32, UPRINTER=33, DSD=34, EXPANDTABS=35, NOEXPANDTABS=36, FLOWOVER=37, 
		MISSOVER=38, PAD=39, NOPAD=40, SCANOVER=41, SHAREBUFFERS=42, STOPOVER=43, 
		TRUNCOVER=44, V_INFILE_=45, SEMICOLON=46, OF=47, EQ=48, NE=49, GT=50, 
		LT=51, GE=52, LE=53, IN=54, EQC=55, NEC=56, GTC=57, LTC=58, GEC=59, LEC=60, 
		INC=61, AND=62, OR=63, NOT=64, MIN=65, MAX=66, DateLiteral=67, TimeLiteral=68, 
		DateTimeLiteral=69, BitLiteral=70, NameLiteral=71, HexLiteral=72, STRINGLITERAL=73, 
		INT=74, MissingValueLiteral=75, FloatingPointLiteral=76, Identifier=77, 
		EQUAL=78, COLON=79, COMMA=80, DOLLAR=81, PERCENT=82, ADD=83, SUB=84, MUL=85, 
		DIV=86, VERLINE=87, EXCLAMATION=88, LParentheses=89, RParentheses=90, 
		LBraces=91, RBraces=92, LSqBracket=93, RSqBracket=94, LBracket=95, RBracket=96, 
		WS=97, COMMENT=98;
	public static final int
		RULE_expression = 0, RULE_expressionList = 1, RULE_of_var_list = 2, RULE_in_var_list = 3, 
		RULE_colonInts = 4, RULE_literal = 5;
	private static String[] makeRuleNames() {
		return new String[] {
			"expression", "expressionList", "of_var_list", "in_var_list", "colonInts", 
			"literal"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'abort'", "'abend'", "'cancel'", "'file'", "'return'", "'nolist'", 
			"'array'", "'_NUMERIC_'", "'_CHARACTER_'", "'_ALL_'", "'by'", "'groupformat'", 
			"'notsorted'", "'descending'", "'call'", "'datalines'", "'cards'", "'lines'", 
			"'datalines4'", "'cards4'", "'lines4'", "';;;;'", "'infile'", null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, "';'", null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, "'><'", "'<>'", null, null, null, null, null, null, 
			null, null, "'.'", null, null, "'='", "':'", "','", "'$'", "'%'", "'+'", 
			"'-'", "'*'", "'/'", "'|'", "'!'", "'('", "')'", "'{'", "'}'", "'['", 
			"']'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "ABORT", "ABEND", "CANCEL", "FILE", "RETURN", "NOLIST", "ARRAY", 
			"ARRAY_NUMERIC_ELEMENTS", "ARRAY_CHARACTER_ELEMENTS", "ARRAY_ALL_ELEMENTS", 
			"BY", "GROUPFORMAT", "NOTSORTED", "DESCENDING", "CALL", "DATALINES", 
			"CARDS", "LINES", "DATALINES4", "CARDS4", "LINES4", "END_DATALINES4", 
			"INFILE", "DISK", "DUMMY", "GTERM", "PIPE", "PLOTTER", "PRINTER", "TAPE", 
			"TEMP", "TERMINAL", "UPRINTER", "DSD", "EXPANDTABS", "NOEXPANDTABS", 
			"FLOWOVER", "MISSOVER", "PAD", "NOPAD", "SCANOVER", "SHAREBUFFERS", "STOPOVER", 
			"TRUNCOVER", "V_INFILE_", "SEMICOLON", "OF", "EQ", "NE", "GT", "LT", 
			"GE", "LE", "IN", "EQC", "NEC", "GTC", "LTC", "GEC", "LEC", "INC", "AND", 
			"OR", "NOT", "MIN", "MAX", "DateLiteral", "TimeLiteral", "DateTimeLiteral", 
			"BitLiteral", "NameLiteral", "HexLiteral", "STRINGLITERAL", "INT", "MissingValueLiteral", 
			"FloatingPointLiteral", "Identifier", "EQUAL", "COLON", "COMMA", "DOLLAR", 
			"PERCENT", "ADD", "SUB", "MUL", "DIV", "VERLINE", "EXCLAMATION", "LParentheses", 
			"RParentheses", "LBraces", "RBraces", "LSqBracket", "RSqBracket", "LBracket", 
			"RBracket", "WS", "COMMENT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "CommonParserRules.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public CommonParserRules(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ExpressionContext extends ParserRuleContext {
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(CommonParserRules.Identifier, 0); }
		public TerminalNode LParentheses() { return getToken(CommonParserRules.LParentheses, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode RParentheses() { return getToken(CommonParserRules.RParentheses, 0); }
		public TerminalNode ADD() { return getToken(CommonParserRules.ADD, 0); }
		public TerminalNode SUB() { return getToken(CommonParserRules.SUB, 0); }
		public TerminalNode NOT() { return getToken(CommonParserRules.NOT, 0); }
		public List<TerminalNode> MUL() { return getTokens(CommonParserRules.MUL); }
		public TerminalNode MUL(int i) {
			return getToken(CommonParserRules.MUL, i);
		}
		public TerminalNode MIN() { return getToken(CommonParserRules.MIN, 0); }
		public TerminalNode MAX() { return getToken(CommonParserRules.MAX, 0); }
		public TerminalNode DIV() { return getToken(CommonParserRules.DIV, 0); }
		public TerminalNode PERCENT() { return getToken(CommonParserRules.PERCENT, 0); }
		public List<TerminalNode> VERLINE() { return getTokens(CommonParserRules.VERLINE); }
		public TerminalNode VERLINE(int i) {
			return getToken(CommonParserRules.VERLINE, i);
		}
		public List<TerminalNode> EXCLAMATION() { return getTokens(CommonParserRules.EXCLAMATION); }
		public TerminalNode EXCLAMATION(int i) {
			return getToken(CommonParserRules.EXCLAMATION, i);
		}
		public TerminalNode EQ() { return getToken(CommonParserRules.EQ, 0); }
		public TerminalNode NE() { return getToken(CommonParserRules.NE, 0); }
		public TerminalNode GT() { return getToken(CommonParserRules.GT, 0); }
		public TerminalNode LT() { return getToken(CommonParserRules.LT, 0); }
		public TerminalNode GE() { return getToken(CommonParserRules.GE, 0); }
		public TerminalNode LE() { return getToken(CommonParserRules.LE, 0); }
		public TerminalNode EQC() { return getToken(CommonParserRules.EQC, 0); }
		public TerminalNode NEC() { return getToken(CommonParserRules.NEC, 0); }
		public TerminalNode GTC() { return getToken(CommonParserRules.GTC, 0); }
		public TerminalNode LTC() { return getToken(CommonParserRules.LTC, 0); }
		public TerminalNode GEC() { return getToken(CommonParserRules.GEC, 0); }
		public TerminalNode LEC() { return getToken(CommonParserRules.LEC, 0); }
		public TerminalNode AND() { return getToken(CommonParserRules.AND, 0); }
		public TerminalNode OR() { return getToken(CommonParserRules.OR, 0); }
		public TerminalNode EQUAL() { return getToken(CommonParserRules.EQUAL, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public TerminalNode LBraces() { return getToken(CommonParserRules.LBraces, 0); }
		public TerminalNode RBraces() { return getToken(CommonParserRules.RBraces, 0); }
		public TerminalNode LSqBracket() { return getToken(CommonParserRules.LSqBracket, 0); }
		public TerminalNode RSqBracket() { return getToken(CommonParserRules.RSqBracket, 0); }
		public In_var_listContext in_var_list() {
			return getRuleContext(In_var_listContext.class,0);
		}
		public TerminalNode IN() { return getToken(CommonParserRules.IN, 0); }
		public TerminalNode INC() { return getToken(CommonParserRules.INC, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CommonParserRulesListener ) ((CommonParserRulesListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonParserRulesListener ) ((CommonParserRulesListener)listener).exitExpression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonParserRulesVisitor ) return ((CommonParserRulesVisitor<? extends T>)visitor).visitExpression(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 0;
		enterRecursionRule(_localctx, 0, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(23);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case DateLiteral:
			case TimeLiteral:
			case DateTimeLiteral:
			case BitLiteral:
			case NameLiteral:
			case HexLiteral:
			case STRINGLITERAL:
			case INT:
			case MissingValueLiteral:
			case FloatingPointLiteral:
				{
				setState(13);
				literal();
				}
				break;
			case Identifier:
				{
				setState(14);
				match(Identifier);
				}
				break;
			case LParentheses:
				{
				setState(15);
				match(LParentheses);
				setState(16);
				expression(0);
				setState(17);
				match(RParentheses);
				}
				break;
			case ADD:
			case SUB:
				{
				setState(19);
				_la = _input.LA(1);
				if ( !(_la==ADD || _la==SUB) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(20);
				expression(12);
				}
				break;
			case NOT:
				{
				setState(21);
				match(NOT);
				setState(22);
				expression(11);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(82);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(80);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(25);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(26);
						match(MUL);
						setState(27);
						match(MUL);
						setState(28);
						expression(13);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(29);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(30);
						match(MIN);
						setState(31);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(32);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(33);
						match(MAX);
						setState(34);
						expression(10);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(35);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(36);
						_la = _input.LA(1);
						if ( !(((((_la - 82)) & ~0x3f) == 0 && ((1L << (_la - 82)) & ((1L << (PERCENT - 82)) | (1L << (MUL - 82)) | (1L << (DIV - 82)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(37);
						expression(9);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(38);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(39);
						_la = _input.LA(1);
						if ( !(_la==ADD || _la==SUB) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(40);
						expression(8);
						}
						break;
					case 6:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(41);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(46);
						_errHandler.sync(this);
						switch (_input.LA(1)) {
						case VERLINE:
							{
							setState(42);
							match(VERLINE);
							setState(43);
							match(VERLINE);
							}
							break;
						case EXCLAMATION:
							{
							setState(44);
							match(EXCLAMATION);
							setState(45);
							match(EXCLAMATION);
							}
							break;
						default:
							throw new NoViableAltException(this);
						}
						setState(48);
						expression(7);
						}
						break;
					case 7:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(49);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(50);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << EQ) | (1L << NE) | (1L << GT) | (1L << LT) | (1L << GE) | (1L << LE))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(51);
						expression(6);
						}
						break;
					case 8:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(52);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(53);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << EQC) | (1L << NEC) | (1L << GTC) | (1L << LTC) | (1L << GEC) | (1L << LEC))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(54);
						expression(5);
						}
						break;
					case 9:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(55);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(56);
						_la = _input.LA(1);
						if ( !(_la==AND || _la==OR) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(57);
						expression(3);
						}
						break;
					case 10:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(58);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(59);
						match(EQUAL);
						setState(60);
						expression(1);
						}
						break;
					case 11:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(61);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(62);
						match(LParentheses);
						setState(64);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (((((_la - 47)) & ~0x3f) == 0 && ((1L << (_la - 47)) & ((1L << (OF - 47)) | (1L << (NOT - 47)) | (1L << (DateLiteral - 47)) | (1L << (TimeLiteral - 47)) | (1L << (DateTimeLiteral - 47)) | (1L << (BitLiteral - 47)) | (1L << (NameLiteral - 47)) | (1L << (HexLiteral - 47)) | (1L << (STRINGLITERAL - 47)) | (1L << (INT - 47)) | (1L << (MissingValueLiteral - 47)) | (1L << (FloatingPointLiteral - 47)) | (1L << (Identifier - 47)) | (1L << (ADD - 47)) | (1L << (SUB - 47)) | (1L << (LParentheses - 47)))) != 0)) {
							{
							setState(63);
							expressionList(0);
							}
						}

						setState(66);
						match(RParentheses);
						}
						break;
					case 12:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(67);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(68);
						match(LBraces);
						setState(69);
						expression(0);
						setState(70);
						match(RBraces);
						}
						break;
					case 13:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(72);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(73);
						match(LSqBracket);
						setState(74);
						expression(0);
						setState(75);
						match(RSqBracket);
						}
						break;
					case 14:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(77);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(78);
						_la = _input.LA(1);
						if ( !(_la==IN || _la==INC) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(79);
						in_var_list();
						}
						break;
					}
					} 
				}
				setState(84);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ExpressionListContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<Of_var_listContext> of_var_list() {
			return getRuleContexts(Of_var_listContext.class);
		}
		public Of_var_listContext of_var_list(int i) {
			return getRuleContext(Of_var_listContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(CommonParserRules.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(CommonParserRules.COMMA, i);
		}
		public List<ExpressionListContext> expressionList() {
			return getRuleContexts(ExpressionListContext.class);
		}
		public ExpressionListContext expressionList(int i) {
			return getRuleContext(ExpressionListContext.class,i);
		}
		public ExpressionListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expressionList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CommonParserRulesListener ) ((CommonParserRulesListener)listener).enterExpressionList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonParserRulesListener ) ((CommonParserRulesListener)listener).exitExpressionList(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonParserRulesVisitor ) return ((CommonParserRulesVisitor<? extends T>)visitor).visitExpressionList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ExpressionListContext expressionList() throws RecognitionException {
		return expressionList(0);
	}

	private ExpressionListContext expressionList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionListContext _localctx = new ExpressionListContext(_ctx, _parentState);
		ExpressionListContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_expressionList, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(88);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NOT:
			case DateLiteral:
			case TimeLiteral:
			case DateTimeLiteral:
			case BitLiteral:
			case NameLiteral:
			case HexLiteral:
			case STRINGLITERAL:
			case INT:
			case MissingValueLiteral:
			case FloatingPointLiteral:
			case Identifier:
			case ADD:
			case SUB:
			case LParentheses:
				{
				setState(86);
				expression(0);
				}
				break;
			case OF:
				{
				setState(87);
				of_var_list();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(97);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(90);
					match(COMMA);
					setState(93);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case NOT:
					case DateLiteral:
					case TimeLiteral:
					case DateTimeLiteral:
					case BitLiteral:
					case NameLiteral:
					case HexLiteral:
					case STRINGLITERAL:
					case INT:
					case MissingValueLiteral:
					case FloatingPointLiteral:
					case Identifier:
					case ADD:
					case SUB:
					case LParentheses:
						{
						setState(91);
						expression(0);
						}
						break;
					case OF:
						{
						setState(92);
						of_var_list();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					} 
				}
				setState(99);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			}
			}
			_ctx.stop = _input.LT(-1);
			setState(109);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ExpressionListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_expressionList);
					setState(100);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(102); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(101);
						match(COMMA);
						}
						}
						setState(104); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==COMMA );
					setState(106);
					expressionList(2);
					}
					} 
				}
				setState(111);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class Of_var_listContext extends ParserRuleContext {
		public List<TerminalNode> OF() { return getTokens(CommonParserRules.OF); }
		public TerminalNode OF(int i) {
			return getToken(CommonParserRules.OF, i);
		}
		public List<TerminalNode> Identifier() { return getTokens(CommonParserRules.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(CommonParserRules.Identifier, i);
		}
		public List<TerminalNode> SUB() { return getTokens(CommonParserRules.SUB); }
		public TerminalNode SUB(int i) {
			return getToken(CommonParserRules.SUB, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(CommonParserRules.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(CommonParserRules.COMMA, i);
		}
		public TerminalNode LSqBracket() { return getToken(CommonParserRules.LSqBracket, 0); }
		public TerminalNode MUL() { return getToken(CommonParserRules.MUL, 0); }
		public TerminalNode RSqBracket() { return getToken(CommonParserRules.RSqBracket, 0); }
		public Of_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_of_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CommonParserRulesListener ) ((CommonParserRulesListener)listener).enterOf_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonParserRulesListener ) ((CommonParserRulesListener)listener).exitOf_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonParserRulesVisitor ) return ((CommonParserRulesVisitor<? extends T>)visitor).visitOf_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Of_var_listContext of_var_list() throws RecognitionException {
		Of_var_listContext _localctx = new Of_var_listContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_of_var_list);
		int _la;
		try {
			int _alt;
			setState(142);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(112);
				match(OF);
				{
				setState(113);
				match(Identifier);
				setState(114);
				match(SUB);
				setState(115);
				match(Identifier);
				}
				setState(126);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(119);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==COMMA) {
							{
							setState(117);
							match(COMMA);
							setState(118);
							match(OF);
							}
						}

						{
						setState(121);
						match(Identifier);
						setState(122);
						match(SUB);
						setState(123);
						match(Identifier);
						}
						}
						} 
					}
					setState(128);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(129);
				match(OF);
				setState(130);
				match(Identifier);
				setState(134);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(131);
						match(Identifier);
						}
						} 
					}
					setState(136);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(137);
				match(OF);
				setState(138);
				match(Identifier);
				setState(139);
				match(LSqBracket);
				setState(140);
				match(MUL);
				setState(141);
				match(RSqBracket);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class In_var_listContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(CommonParserRules.Identifier, 0); }
		public TerminalNode LParentheses() { return getToken(CommonParserRules.LParentheses, 0); }
		public TerminalNode RParentheses() { return getToken(CommonParserRules.RParentheses, 0); }
		public List<LiteralContext> literal() {
			return getRuleContexts(LiteralContext.class);
		}
		public LiteralContext literal(int i) {
			return getRuleContext(LiteralContext.class,i);
		}
		public List<ColonIntsContext> colonInts() {
			return getRuleContexts(ColonIntsContext.class);
		}
		public ColonIntsContext colonInts(int i) {
			return getRuleContext(ColonIntsContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(CommonParserRules.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(CommonParserRules.COMMA, i);
		}
		public In_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_in_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CommonParserRulesListener ) ((CommonParserRulesListener)listener).enterIn_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonParserRulesListener ) ((CommonParserRulesListener)listener).exitIn_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonParserRulesVisitor ) return ((CommonParserRulesVisitor<? extends T>)visitor).visitIn_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final In_var_listContext in_var_list() throws RecognitionException {
		In_var_listContext _localctx = new In_var_listContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_in_var_list);
		int _la;
		try {
			setState(162);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(144);
				match(Identifier);
				}
				break;
			case LParentheses:
				enterOuterAlt(_localctx, 2);
				{
				setState(145);
				match(LParentheses);
				setState(148);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
				case 1:
					{
					setState(146);
					literal();
					}
					break;
				case 2:
					{
					setState(147);
					colonInts();
					}
					break;
				}
				setState(157);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(150);
					match(COMMA);
					setState(153);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
					case 1:
						{
						setState(151);
						literal();
						}
						break;
					case 2:
						{
						setState(152);
						colonInts();
						}
						break;
					}
					}
					}
					setState(159);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(160);
				match(RParentheses);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ColonIntsContext extends ParserRuleContext {
		public List<TerminalNode> INT() { return getTokens(CommonParserRules.INT); }
		public TerminalNode INT(int i) {
			return getToken(CommonParserRules.INT, i);
		}
		public TerminalNode COLON() { return getToken(CommonParserRules.COLON, 0); }
		public ColonIntsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_colonInts; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CommonParserRulesListener ) ((CommonParserRulesListener)listener).enterColonInts(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonParserRulesListener ) ((CommonParserRulesListener)listener).exitColonInts(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonParserRulesVisitor ) return ((CommonParserRulesVisitor<? extends T>)visitor).visitColonInts(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ColonIntsContext colonInts() throws RecognitionException {
		ColonIntsContext _localctx = new ColonIntsContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_colonInts);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(164);
			match(INT);
			setState(165);
			match(COLON);
			setState(166);
			match(INT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LiteralContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(CommonParserRules.INT, 0); }
		public TerminalNode FloatingPointLiteral() { return getToken(CommonParserRules.FloatingPointLiteral, 0); }
		public TerminalNode STRINGLITERAL() { return getToken(CommonParserRules.STRINGLITERAL, 0); }
		public TerminalNode DateLiteral() { return getToken(CommonParserRules.DateLiteral, 0); }
		public TerminalNode TimeLiteral() { return getToken(CommonParserRules.TimeLiteral, 0); }
		public TerminalNode DateTimeLiteral() { return getToken(CommonParserRules.DateTimeLiteral, 0); }
		public TerminalNode BitLiteral() { return getToken(CommonParserRules.BitLiteral, 0); }
		public TerminalNode NameLiteral() { return getToken(CommonParserRules.NameLiteral, 0); }
		public TerminalNode HexLiteral() { return getToken(CommonParserRules.HexLiteral, 0); }
		public TerminalNode MissingValueLiteral() { return getToken(CommonParserRules.MissingValueLiteral, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CommonParserRulesListener ) ((CommonParserRulesListener)listener).enterLiteral(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonParserRulesListener ) ((CommonParserRulesListener)listener).exitLiteral(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonParserRulesVisitor ) return ((CommonParserRulesVisitor<? extends T>)visitor).visitLiteral(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(168);
			_la = _input.LA(1);
			if ( !(((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & ((1L << (DateLiteral - 67)) | (1L << (TimeLiteral - 67)) | (1L << (DateTimeLiteral - 67)) | (1L << (BitLiteral - 67)) | (1L << (NameLiteral - 67)) | (1L << (HexLiteral - 67)) | (1L << (STRINGLITERAL - 67)) | (1L << (INT - 67)) | (1L << (MissingValueLiteral - 67)) | (1L << (FloatingPointLiteral - 67)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 0:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		case 1:
			return expressionList_sempred((ExpressionListContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 13);
		case 1:
			return precpred(_ctx, 10);
		case 2:
			return precpred(_ctx, 9);
		case 3:
			return precpred(_ctx, 8);
		case 4:
			return precpred(_ctx, 7);
		case 5:
			return precpred(_ctx, 6);
		case 6:
			return precpred(_ctx, 5);
		case 7:
			return precpred(_ctx, 4);
		case 8:
			return precpred(_ctx, 2);
		case 9:
			return precpred(_ctx, 1);
		case 10:
			return precpred(_ctx, 16);
		case 11:
			return precpred(_ctx, 15);
		case 12:
			return precpred(_ctx, 14);
		case 13:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean expressionList_sempred(ExpressionListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 14:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3d\u00ad\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\5\2\32\n\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\5\2\61\n\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\5\2C\n\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\7\2S\n\2\f\2\16\2V\13\2\3\3\3"+
		"\3\3\3\5\3[\n\3\3\3\3\3\3\3\5\3`\n\3\7\3b\n\3\f\3\16\3e\13\3\3\3\3\3\6"+
		"\3i\n\3\r\3\16\3j\3\3\7\3n\n\3\f\3\16\3q\13\3\3\4\3\4\3\4\3\4\3\4\3\4"+
		"\3\4\5\4z\n\4\3\4\3\4\3\4\7\4\177\n\4\f\4\16\4\u0082\13\4\3\4\3\4\3\4"+
		"\7\4\u0087\n\4\f\4\16\4\u008a\13\4\3\4\3\4\3\4\3\4\3\4\5\4\u0091\n\4\3"+
		"\5\3\5\3\5\3\5\5\5\u0097\n\5\3\5\3\5\3\5\5\5\u009c\n\5\7\5\u009e\n\5\f"+
		"\5\16\5\u00a1\13\5\3\5\3\5\5\5\u00a5\n\5\3\6\3\6\3\6\3\6\3\7\3\7\3\7\2"+
		"\4\2\4\b\2\4\6\b\n\f\2\t\3\2UV\4\2TTWX\3\2\62\67\3\29>\3\2@A\4\288??\3"+
		"\2EN\2\u00c8\2\31\3\2\2\2\4W\3\2\2\2\6\u0090\3\2\2\2\b\u00a4\3\2\2\2\n"+
		"\u00a6\3\2\2\2\f\u00aa\3\2\2\2\16\17\b\2\1\2\17\32\5\f\7\2\20\32\7O\2"+
		"\2\21\22\7[\2\2\22\23\5\2\2\2\23\24\7\\\2\2\24\32\3\2\2\2\25\26\t\2\2"+
		"\2\26\32\5\2\2\16\27\30\7B\2\2\30\32\5\2\2\r\31\16\3\2\2\2\31\20\3\2\2"+
		"\2\31\21\3\2\2\2\31\25\3\2\2\2\31\27\3\2\2\2\32T\3\2\2\2\33\34\f\17\2"+
		"\2\34\35\7W\2\2\35\36\7W\2\2\36S\5\2\2\17\37 \f\f\2\2 !\7C\2\2!S\5\2\2"+
		"\r\"#\f\13\2\2#$\7D\2\2$S\5\2\2\f%&\f\n\2\2&\'\t\3\2\2\'S\5\2\2\13()\f"+
		"\t\2\2)*\t\2\2\2*S\5\2\2\n+\60\f\b\2\2,-\7Y\2\2-\61\7Y\2\2./\7Z\2\2/\61"+
		"\7Z\2\2\60,\3\2\2\2\60.\3\2\2\2\61\62\3\2\2\2\62S\5\2\2\t\63\64\f\7\2"+
		"\2\64\65\t\4\2\2\65S\5\2\2\b\66\67\f\6\2\2\678\t\5\2\28S\5\2\2\79:\f\4"+
		"\2\2:;\t\6\2\2;S\5\2\2\5<=\f\3\2\2=>\7P\2\2>S\5\2\2\3?@\f\22\2\2@B\7["+
		"\2\2AC\5\4\3\2BA\3\2\2\2BC\3\2\2\2CD\3\2\2\2DS\7\\\2\2EF\f\21\2\2FG\7"+
		"]\2\2GH\5\2\2\2HI\7^\2\2IS\3\2\2\2JK\f\20\2\2KL\7_\2\2LM\5\2\2\2MN\7`"+
		"\2\2NS\3\2\2\2OP\f\5\2\2PQ\t\7\2\2QS\5\b\5\2R\33\3\2\2\2R\37\3\2\2\2R"+
		"\"\3\2\2\2R%\3\2\2\2R(\3\2\2\2R+\3\2\2\2R\63\3\2\2\2R\66\3\2\2\2R9\3\2"+
		"\2\2R<\3\2\2\2R?\3\2\2\2RE\3\2\2\2RJ\3\2\2\2RO\3\2\2\2SV\3\2\2\2TR\3\2"+
		"\2\2TU\3\2\2\2U\3\3\2\2\2VT\3\2\2\2WZ\b\3\1\2X[\5\2\2\2Y[\5\6\4\2ZX\3"+
		"\2\2\2ZY\3\2\2\2[c\3\2\2\2\\_\7R\2\2]`\5\2\2\2^`\5\6\4\2_]\3\2\2\2_^\3"+
		"\2\2\2`b\3\2\2\2a\\\3\2\2\2be\3\2\2\2ca\3\2\2\2cd\3\2\2\2do\3\2\2\2ec"+
		"\3\2\2\2fh\f\3\2\2gi\7R\2\2hg\3\2\2\2ij\3\2\2\2jh\3\2\2\2jk\3\2\2\2kl"+
		"\3\2\2\2ln\5\4\3\4mf\3\2\2\2nq\3\2\2\2om\3\2\2\2op\3\2\2\2p\5\3\2\2\2"+
		"qo\3\2\2\2rs\7\61\2\2st\7O\2\2tu\7V\2\2uv\7O\2\2v\u0080\3\2\2\2wx\7R\2"+
		"\2xz\7\61\2\2yw\3\2\2\2yz\3\2\2\2z{\3\2\2\2{|\7O\2\2|}\7V\2\2}\177\7O"+
		"\2\2~y\3\2\2\2\177\u0082\3\2\2\2\u0080~\3\2\2\2\u0080\u0081\3\2\2\2\u0081"+
		"\u0091\3\2\2\2\u0082\u0080\3\2\2\2\u0083\u0084\7\61\2\2\u0084\u0088\7"+
		"O\2\2\u0085\u0087\7O\2\2\u0086\u0085\3\2\2\2\u0087\u008a\3\2\2\2\u0088"+
		"\u0086\3\2\2\2\u0088\u0089\3\2\2\2\u0089\u0091\3\2\2\2\u008a\u0088\3\2"+
		"\2\2\u008b\u008c\7\61\2\2\u008c\u008d\7O\2\2\u008d\u008e\7_\2\2\u008e"+
		"\u008f\7W\2\2\u008f\u0091\7`\2\2\u0090r\3\2\2\2\u0090\u0083\3\2\2\2\u0090"+
		"\u008b\3\2\2\2\u0091\7\3\2\2\2\u0092\u00a5\7O\2\2\u0093\u0096\7[\2\2\u0094"+
		"\u0097\5\f\7\2\u0095\u0097\5\n\6\2\u0096\u0094\3\2\2\2\u0096\u0095\3\2"+
		"\2\2\u0097\u009f\3\2\2\2\u0098\u009b\7R\2\2\u0099\u009c\5\f\7\2\u009a"+
		"\u009c\5\n\6\2\u009b\u0099\3\2\2\2\u009b\u009a\3\2\2\2\u009c\u009e\3\2"+
		"\2\2\u009d\u0098\3\2\2\2\u009e\u00a1\3\2\2\2\u009f\u009d\3\2\2\2\u009f"+
		"\u00a0\3\2\2\2\u00a0\u00a2\3\2\2\2\u00a1\u009f\3\2\2\2\u00a2\u00a3\7\\"+
		"\2\2\u00a3\u00a5\3\2\2\2\u00a4\u0092\3\2\2\2\u00a4\u0093\3\2\2\2\u00a5"+
		"\t\3\2\2\2\u00a6\u00a7\7L\2\2\u00a7\u00a8\7Q\2\2\u00a8\u00a9\7L\2\2\u00a9"+
		"\13\3\2\2\2\u00aa\u00ab\t\b\2\2\u00ab\r\3\2\2\2\24\31\60BRTZ_cjoy\u0080"+
		"\u0088\u0090\u0096\u009b\u009f\u00a4";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}