// Generated from AssignmentStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class AssignmentStmtParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		ABEND=18, END=19, LENGTH=20, QKUPCASE=21, SYSEVALF=22, ABORT=23, EVAL=24, 
		LET=25, QSCAN=26, SYSEXEC=27, ACT=28, FILE=29, LIST=30, QSUBSTR=31, SYSFUNC=32, 
		ACTIVATE=33, GLOBAL=34, LISTM=35, QSYSFUNC=36, SYSGET=37, BQUOTE=38, GO=39, 
		LOCAL=40, QUOTE=41, SYSRPUT=42, BY=43, GOTO=44, MACRO=45, QUPCASE=46, 
		THEN=47, CLEAR=48, IF=49, MEND=50, RESOLVE=51, TO=52, CLOSE=53, INC=54, 
		PAUSE=55, RETURN=56, TSO=57, CMS=58, INCLUDE=59, NRSTR=60, RUN=61, UNQUOTE=62, 
		COMANDR=63, INDEX=64, ON=65, SAVE=66, UNSTR=67, COPY=68, INFILE=69, OPEN=70, 
		SCAN=71, UNTIL=72, DEACT=73, INPUT=74, PUT=75, STOP=76, UPCASE=77, DEL=78, 
		KCMPRES=79, NRBQUOTE=80, STR=81, WHILE=82, DELETE=83, KINDEX=84, NRQUOTE=85, 
		SYSCALL=86, WINDOW=87, DISPLAY=88, KLEFT=89, METASYM=90, SUBSTR=91, DMIDSPLY=92, 
		KLENGTH=93, QKCMPRES=94, SUPERQ=95, DMISPLIT=96, KSCAN=97, QKLEFT=98, 
		SYMDEL=99, DO=100, KSUBSTR=101, QKSCAN=102, SYMEXIST=103, EDIT=104, KTRIM=105, 
		QKSUBSTR=106, SYMGLOBL=107, ELSE=108, KUPCASE=109, QKTRIM=110, SYMLOCAL=111, 
		Tk_NULL=112, CANCEL=113, NOLIST=114, ARRAY=115, ARRAY_NUMERIC_ELEMENTS=116, 
		ARRAY_CHARACTER_ELEMENTS=117, ARRAY_ALL_ELEMENTS=118, GROUPFORMAT=119, 
		NOTSORTED=120, DESCENDING=121, CALL=122, DEBUG=123, NESTING=124, STACK=125, 
		READ=126, PW=127, SOURCE=128, VIEW=129, PGM=130, ENCRYPT=131, NOSAVE=132, 
		DATALINES=133, CARDS=134, LINES=135, DATALINES4=136, CARDS4=137, LINES4=138, 
		END_DATALINES4=139, ALTER=140, DISK=141, DUMMY=142, GTERM=143, PIPE=144, 
		PLOTTER=145, PRINTER=146, TAPE=147, TEMP=148, TERMINAL=149, UPRINTER=150, 
		DSD=151, EXPANDTABS=152, NOEXPANDTABS=153, FLOWOVER=154, MISSOVER=155, 
		PAD=156, NOPAD=157, SCANOVER=158, SHAREBUFFERS=159, STOPOVER=160, TRUNCOVER=161, 
		V_INFILE_=162, INPUT_ODS=163, DATE=164, DATETIME=165, DDMMYY=166, INFORMAT_COMMA=167, 
		INFORMAT_CHAR=168, DROP=169, PROC=170, ANOVA=171, MEANS=172, REG=173, 
		CORR=174, SGPLOT=175, PRINT=176, DATA=177, GLM=178, FREQ=179, SQL=180, 
		UNIVARIATE=181, NPAR1WAY=182, IMPORT=183, SORT=184, DATASETS=185, TABULATE=186, 
		RANK=187, CHART=188, LOGISTIC=189, SURVEYSELECT=190, Informat=191, DOLLAR=192, 
		EQ=193, NE=194, GT=195, LT=196, GE=197, LE=198, IN=199, EQC=200, NEC=201, 
		GTC=202, LTC=203, GEC=204, LEC=205, INColon=206, AND=207, OR=208, NOT=209, 
		MIN=210, MAX=211, DateLiteral=212, TimeLiteral=213, DateTimeLiteral=214, 
		BitLiteral=215, NameLiteral=216, HexLiteral=217, STRINGLITERAL=218, INT=219, 
		FloatingPointLiteral=220, Identifier=221, DOT=222, AT=223, EQUAL=224, 
		COMMA=225, LBracket=226, RBracket=227, WS=228, COMMENT=229, LINE_COMMENT=230;
	public static final int
		RULE_assign_main = 0, RULE_assign_stmt = 1, RULE_expression = 2, RULE_expressionList = 3, 
		RULE_of_var_list = 4, RULE_identifiers_list = 5, RULE_in_var_list = 6, 
		RULE_colonInts = 7, RULE_literal = 8, RULE_variables = 9;
	private static String[] makeRuleNames() {
		return new String[] {
			"assign_main", "assign_stmt", "expression", "expressionList", "of_var_list", 
			"identifiers_list", "in_var_list", "colonInts", "literal", "variables"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'**'", "'+'", 
			"'-'", "'*'", "'/'", "'%'", "'||'", "'!!'", "'of'", "':'", null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, "';;;;'", 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, "'$'", null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, "'><'", "'<>'", 
			null, null, null, null, null, null, null, null, null, null, "'.'", "'@'", 
			"'='", "','"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, "ABEND", "END", "LENGTH", "QKUPCASE", 
			"SYSEVALF", "ABORT", "EVAL", "LET", "QSCAN", "SYSEXEC", "ACT", "FILE", 
			"LIST", "QSUBSTR", "SYSFUNC", "ACTIVATE", "GLOBAL", "LISTM", "QSYSFUNC", 
			"SYSGET", "BQUOTE", "GO", "LOCAL", "QUOTE", "SYSRPUT", "BY", "GOTO", 
			"MACRO", "QUPCASE", "THEN", "CLEAR", "IF", "MEND", "RESOLVE", "TO", "CLOSE", 
			"INC", "PAUSE", "RETURN", "TSO", "CMS", "INCLUDE", "NRSTR", "RUN", "UNQUOTE", 
			"COMANDR", "INDEX", "ON", "SAVE", "UNSTR", "COPY", "INFILE", "OPEN", 
			"SCAN", "UNTIL", "DEACT", "INPUT", "PUT", "STOP", "UPCASE", "DEL", "KCMPRES", 
			"NRBQUOTE", "STR", "WHILE", "DELETE", "KINDEX", "NRQUOTE", "SYSCALL", 
			"WINDOW", "DISPLAY", "KLEFT", "METASYM", "SUBSTR", "DMIDSPLY", "KLENGTH", 
			"QKCMPRES", "SUPERQ", "DMISPLIT", "KSCAN", "QKLEFT", "SYMDEL", "DO", 
			"KSUBSTR", "QKSCAN", "SYMEXIST", "EDIT", "KTRIM", "QKSUBSTR", "SYMGLOBL", 
			"ELSE", "KUPCASE", "QKTRIM", "SYMLOCAL", "Tk_NULL", "CANCEL", "NOLIST", 
			"ARRAY", "ARRAY_NUMERIC_ELEMENTS", "ARRAY_CHARACTER_ELEMENTS", "ARRAY_ALL_ELEMENTS", 
			"GROUPFORMAT", "NOTSORTED", "DESCENDING", "CALL", "DEBUG", "NESTING", 
			"STACK", "READ", "PW", "SOURCE", "VIEW", "PGM", "ENCRYPT", "NOSAVE", 
			"DATALINES", "CARDS", "LINES", "DATALINES4", "CARDS4", "LINES4", "END_DATALINES4", 
			"ALTER", "DISK", "DUMMY", "GTERM", "PIPE", "PLOTTER", "PRINTER", "TAPE", 
			"TEMP", "TERMINAL", "UPRINTER", "DSD", "EXPANDTABS", "NOEXPANDTABS", 
			"FLOWOVER", "MISSOVER", "PAD", "NOPAD", "SCANOVER", "SHAREBUFFERS", "STOPOVER", 
			"TRUNCOVER", "V_INFILE_", "INPUT_ODS", "DATE", "DATETIME", "DDMMYY", 
			"INFORMAT_COMMA", "INFORMAT_CHAR", "DROP", "PROC", "ANOVA", "MEANS", 
			"REG", "CORR", "SGPLOT", "PRINT", "DATA", "GLM", "FREQ", "SQL", "UNIVARIATE", 
			"NPAR1WAY", "IMPORT", "SORT", "DATASETS", "TABULATE", "RANK", "CHART", 
			"LOGISTIC", "SURVEYSELECT", "Informat", "DOLLAR", "EQ", "NE", "GT", "LT", 
			"GE", "LE", "IN", "EQC", "NEC", "GTC", "LTC", "GEC", "LEC", "INColon", 
			"AND", "OR", "NOT", "MIN", "MAX", "DateLiteral", "TimeLiteral", "DateTimeLiteral", 
			"BitLiteral", "NameLiteral", "HexLiteral", "STRINGLITERAL", "INT", "FloatingPointLiteral", 
			"Identifier", "DOT", "AT", "EQUAL", "COMMA", "LBracket", "RBracket", 
			"WS", "COMMENT", "LINE_COMMENT"
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
	public String getGrammarFileName() { return "AssignmentStmt.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public AssignmentStmtParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Assign_mainContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(AssignmentStmtParser.EOF, 0); }
		public List<Assign_stmtContext> assign_stmt() {
			return getRuleContexts(Assign_stmtContext.class);
		}
		public Assign_stmtContext assign_stmt(int i) {
			return getRuleContext(Assign_stmtContext.class,i);
		}
		public Assign_mainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assign_main; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).enterAssign_main(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).exitAssign_main(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof AssignmentStmtVisitor ) return ((AssignmentStmtVisitor<? extends T>)visitor).visitAssign_main(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Assign_mainContext assign_main() throws RecognitionException {
		Assign_mainContext _localctx = new Assign_mainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_assign_main);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(23);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Identifier) {
				{
				{
				setState(20);
				assign_stmt();
				}
				}
				setState(25);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(26);
			match(EOF);
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

	public static class Assign_stmtContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(AssignmentStmtParser.Identifier, 0); }
		public TerminalNode EQUAL() { return getToken(AssignmentStmtParser.EQUAL, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Assign_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assign_stmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).enterAssign_stmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).exitAssign_stmt(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof AssignmentStmtVisitor ) return ((AssignmentStmtVisitor<? extends T>)visitor).visitAssign_stmt(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Assign_stmtContext assign_stmt() throws RecognitionException {
		Assign_stmtContext _localctx = new Assign_stmtContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_assign_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(28);
			match(Identifier);
			setState(29);
			match(EQUAL);
			setState(30);
			expression(0);
			setState(31);
			match(T__0);
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

	public static class ExpressionContext extends ParserRuleContext {
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(AssignmentStmtParser.Identifier, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode NOT() { return getToken(AssignmentStmtParser.NOT, 0); }
		public TerminalNode MIN() { return getToken(AssignmentStmtParser.MIN, 0); }
		public TerminalNode MAX() { return getToken(AssignmentStmtParser.MAX, 0); }
		public TerminalNode EQ() { return getToken(AssignmentStmtParser.EQ, 0); }
		public TerminalNode NE() { return getToken(AssignmentStmtParser.NE, 0); }
		public TerminalNode GT() { return getToken(AssignmentStmtParser.GT, 0); }
		public TerminalNode LT() { return getToken(AssignmentStmtParser.LT, 0); }
		public TerminalNode GE() { return getToken(AssignmentStmtParser.GE, 0); }
		public TerminalNode LE() { return getToken(AssignmentStmtParser.LE, 0); }
		public TerminalNode EQC() { return getToken(AssignmentStmtParser.EQC, 0); }
		public TerminalNode NEC() { return getToken(AssignmentStmtParser.NEC, 0); }
		public TerminalNode GTC() { return getToken(AssignmentStmtParser.GTC, 0); }
		public TerminalNode LTC() { return getToken(AssignmentStmtParser.LTC, 0); }
		public TerminalNode GEC() { return getToken(AssignmentStmtParser.GEC, 0); }
		public TerminalNode LEC() { return getToken(AssignmentStmtParser.LEC, 0); }
		public TerminalNode AND() { return getToken(AssignmentStmtParser.AND, 0); }
		public TerminalNode OR() { return getToken(AssignmentStmtParser.OR, 0); }
		public TerminalNode EQUAL() { return getToken(AssignmentStmtParser.EQUAL, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public In_var_listContext in_var_list() {
			return getRuleContext(In_var_listContext.class,0);
		}
		public TerminalNode IN() { return getToken(AssignmentStmtParser.IN, 0); }
		public TerminalNode INColon() { return getToken(AssignmentStmtParser.INColon, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).exitExpression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof AssignmentStmtVisitor ) return ((AssignmentStmtVisitor<? extends T>)visitor).visitExpression(this);
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
		int _startState = 4;
		enterRecursionRule(_localctx, 4, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(44);
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
			case FloatingPointLiteral:
			case DOT:
				{
				setState(34);
				literal();
				}
				break;
			case Identifier:
				{
				setState(35);
				match(Identifier);
				}
				break;
			case T__1:
				{
				setState(36);
				match(T__1);
				setState(37);
				expression(0);
				setState(38);
				match(T__2);
				}
				break;
			case T__8:
			case T__9:
				{
				setState(40);
				_la = _input.LA(1);
				if ( !(_la==T__8 || _la==T__9) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(41);
				expression(12);
				}
				break;
			case NOT:
				{
				setState(42);
				match(NOT);
				setState(43);
				expression(11);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(97);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(95);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(46);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(47);
						match(T__7);
						setState(48);
						expression(13);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(49);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(50);
						match(MIN);
						setState(51);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(52);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(53);
						match(MAX);
						setState(54);
						expression(10);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(55);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(56);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__10) | (1L << T__11) | (1L << T__12))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(57);
						expression(9);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(58);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(59);
						_la = _input.LA(1);
						if ( !(_la==T__8 || _la==T__9) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(60);
						expression(8);
						}
						break;
					case 6:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(61);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(62);
						_la = _input.LA(1);
						if ( !(_la==T__13 || _la==T__14) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(63);
						expression(7);
						}
						break;
					case 7:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(64);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(65);
						_la = _input.LA(1);
						if ( !(((((_la - 193)) & ~0x3f) == 0 && ((1L << (_la - 193)) & ((1L << (EQ - 193)) | (1L << (NE - 193)) | (1L << (GT - 193)) | (1L << (LT - 193)) | (1L << (GE - 193)) | (1L << (LE - 193)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(66);
						expression(6);
						}
						break;
					case 8:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(67);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(68);
						_la = _input.LA(1);
						if ( !(((((_la - 200)) & ~0x3f) == 0 && ((1L << (_la - 200)) & ((1L << (EQC - 200)) | (1L << (NEC - 200)) | (1L << (GTC - 200)) | (1L << (LTC - 200)) | (1L << (GEC - 200)) | (1L << (LEC - 200)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(69);
						expression(5);
						}
						break;
					case 9:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(70);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(71);
						_la = _input.LA(1);
						if ( !(_la==AND || _la==OR) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(72);
						expression(3);
						}
						break;
					case 10:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(73);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(74);
						match(EQUAL);
						setState(75);
						expression(1);
						}
						break;
					case 11:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(76);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(77);
						match(T__1);
						setState(79);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__1) | (1L << T__8) | (1L << T__9) | (1L << T__15))) != 0) || ((((_la - 209)) & ~0x3f) == 0 && ((1L << (_la - 209)) & ((1L << (NOT - 209)) | (1L << (DateLiteral - 209)) | (1L << (TimeLiteral - 209)) | (1L << (DateTimeLiteral - 209)) | (1L << (BitLiteral - 209)) | (1L << (NameLiteral - 209)) | (1L << (HexLiteral - 209)) | (1L << (STRINGLITERAL - 209)) | (1L << (INT - 209)) | (1L << (FloatingPointLiteral - 209)) | (1L << (Identifier - 209)) | (1L << (DOT - 209)))) != 0)) {
							{
							setState(78);
							expressionList(0);
							}
						}

						setState(81);
						match(T__2);
						}
						break;
					case 12:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(82);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(83);
						match(T__3);
						setState(84);
						expression(0);
						setState(85);
						match(T__4);
						}
						break;
					case 13:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(87);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(88);
						match(T__5);
						setState(89);
						expression(0);
						setState(90);
						match(T__6);
						}
						break;
					case 14:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(92);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(93);
						_la = _input.LA(1);
						if ( !(_la==IN || _la==INColon) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(94);
						in_var_list();
						}
						break;
					}
					} 
				}
				setState(99);
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
		public List<TerminalNode> COMMA() { return getTokens(AssignmentStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(AssignmentStmtParser.COMMA, i);
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
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).enterExpressionList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).exitExpressionList(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof AssignmentStmtVisitor ) return ((AssignmentStmtVisitor<? extends T>)visitor).visitExpressionList(this);
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
		int _startState = 6;
		enterRecursionRule(_localctx, 6, RULE_expressionList, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(103);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__1:
			case T__8:
			case T__9:
			case NOT:
			case DateLiteral:
			case TimeLiteral:
			case DateTimeLiteral:
			case BitLiteral:
			case NameLiteral:
			case HexLiteral:
			case STRINGLITERAL:
			case INT:
			case FloatingPointLiteral:
			case Identifier:
			case DOT:
				{
				setState(101);
				expression(0);
				}
				break;
			case T__15:
				{
				setState(102);
				of_var_list();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(112);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(105);
					match(COMMA);
					setState(108);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case T__1:
					case T__8:
					case T__9:
					case NOT:
					case DateLiteral:
					case TimeLiteral:
					case DateTimeLiteral:
					case BitLiteral:
					case NameLiteral:
					case HexLiteral:
					case STRINGLITERAL:
					case INT:
					case FloatingPointLiteral:
					case Identifier:
					case DOT:
						{
						setState(106);
						expression(0);
						}
						break;
					case T__15:
						{
						setState(107);
						of_var_list();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					} 
				}
				setState(114);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			}
			}
			_ctx.stop = _input.LT(-1);
			setState(124);
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
					setState(115);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(117); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(116);
						match(COMMA);
						}
						}
						setState(119); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==COMMA );
					setState(121);
					expressionList(2);
					}
					} 
				}
				setState(126);
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
		public List<TerminalNode> Identifier() { return getTokens(AssignmentStmtParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(AssignmentStmtParser.Identifier, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(AssignmentStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(AssignmentStmtParser.COMMA, i);
		}
		public Of_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_of_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).enterOf_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).exitOf_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof AssignmentStmtVisitor ) return ((AssignmentStmtVisitor<? extends T>)visitor).visitOf_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Of_var_listContext of_var_list() throws RecognitionException {
		Of_var_listContext _localctx = new Of_var_listContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_of_var_list);
		int _la;
		try {
			int _alt;
			setState(157);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(127);
				match(T__15);
				{
				setState(128);
				match(Identifier);
				setState(129);
				match(T__9);
				setState(130);
				match(Identifier);
				}
				setState(141);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(134);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==COMMA) {
							{
							setState(132);
							match(COMMA);
							setState(133);
							match(T__15);
							}
						}

						{
						setState(136);
						match(Identifier);
						setState(137);
						match(T__9);
						setState(138);
						match(Identifier);
						}
						}
						} 
					}
					setState(143);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(144);
				match(T__15);
				setState(145);
				match(Identifier);
				setState(149);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(146);
						match(Identifier);
						}
						} 
					}
					setState(151);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(152);
				match(T__15);
				setState(153);
				match(Identifier);
				setState(154);
				match(T__5);
				setState(155);
				match(T__10);
				setState(156);
				match(T__6);
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

	public static class Identifiers_listContext extends ParserRuleContext {
		public List<TerminalNode> Identifier() { return getTokens(AssignmentStmtParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(AssignmentStmtParser.Identifier, i);
		}
		public Identifiers_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifiers_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).enterIdentifiers_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).exitIdentifiers_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof AssignmentStmtVisitor ) return ((AssignmentStmtVisitor<? extends T>)visitor).visitIdentifiers_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Identifiers_listContext identifiers_list() throws RecognitionException {
		Identifiers_listContext _localctx = new Identifiers_listContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_identifiers_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(163); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(163);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
				case 1:
					{
					setState(159);
					match(Identifier);
					}
					break;
				case 2:
					{
					setState(160);
					match(Identifier);
					setState(161);
					match(T__9);
					setState(162);
					match(Identifier);
					}
					break;
				}
				}
				setState(165); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==Identifier );
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
		public TerminalNode Identifier() { return getToken(AssignmentStmtParser.Identifier, 0); }
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
		public List<TerminalNode> COMMA() { return getTokens(AssignmentStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(AssignmentStmtParser.COMMA, i);
		}
		public In_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_in_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).enterIn_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).exitIn_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof AssignmentStmtVisitor ) return ((AssignmentStmtVisitor<? extends T>)visitor).visitIn_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final In_var_listContext in_var_list() throws RecognitionException {
		In_var_listContext _localctx = new In_var_listContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_in_var_list);
		int _la;
		try {
			setState(185);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(167);
				match(Identifier);
				}
				break;
			case T__1:
				enterOuterAlt(_localctx, 2);
				{
				setState(168);
				match(T__1);
				setState(171);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
				case 1:
					{
					setState(169);
					literal();
					}
					break;
				case 2:
					{
					setState(170);
					colonInts();
					}
					break;
				}
				setState(180);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(173);
					match(COMMA);
					setState(176);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
					case 1:
						{
						setState(174);
						literal();
						}
						break;
					case 2:
						{
						setState(175);
						colonInts();
						}
						break;
					}
					}
					}
					setState(182);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(183);
				match(T__2);
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
		public List<TerminalNode> INT() { return getTokens(AssignmentStmtParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(AssignmentStmtParser.INT, i);
		}
		public ColonIntsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_colonInts; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).enterColonInts(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).exitColonInts(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof AssignmentStmtVisitor ) return ((AssignmentStmtVisitor<? extends T>)visitor).visitColonInts(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ColonIntsContext colonInts() throws RecognitionException {
		ColonIntsContext _localctx = new ColonIntsContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_colonInts);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(187);
			match(INT);
			setState(188);
			match(T__16);
			setState(189);
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
		public TerminalNode INT() { return getToken(AssignmentStmtParser.INT, 0); }
		public TerminalNode FloatingPointLiteral() { return getToken(AssignmentStmtParser.FloatingPointLiteral, 0); }
		public TerminalNode STRINGLITERAL() { return getToken(AssignmentStmtParser.STRINGLITERAL, 0); }
		public TerminalNode DateLiteral() { return getToken(AssignmentStmtParser.DateLiteral, 0); }
		public TerminalNode TimeLiteral() { return getToken(AssignmentStmtParser.TimeLiteral, 0); }
		public TerminalNode DateTimeLiteral() { return getToken(AssignmentStmtParser.DateTimeLiteral, 0); }
		public TerminalNode BitLiteral() { return getToken(AssignmentStmtParser.BitLiteral, 0); }
		public TerminalNode NameLiteral() { return getToken(AssignmentStmtParser.NameLiteral, 0); }
		public TerminalNode HexLiteral() { return getToken(AssignmentStmtParser.HexLiteral, 0); }
		public TerminalNode DOT() { return getToken(AssignmentStmtParser.DOT, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).enterLiteral(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).exitLiteral(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof AssignmentStmtVisitor ) return ((AssignmentStmtVisitor<? extends T>)visitor).visitLiteral(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(191);
			_la = _input.LA(1);
			if ( !(((((_la - 212)) & ~0x3f) == 0 && ((1L << (_la - 212)) & ((1L << (DateLiteral - 212)) | (1L << (TimeLiteral - 212)) | (1L << (DateTimeLiteral - 212)) | (1L << (BitLiteral - 212)) | (1L << (NameLiteral - 212)) | (1L << (HexLiteral - 212)) | (1L << (STRINGLITERAL - 212)) | (1L << (INT - 212)) | (1L << (FloatingPointLiteral - 212)) | (1L << (DOT - 212)))) != 0)) ) {
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

	public static class VariablesContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(AssignmentStmtParser.Identifier, 0); }
		public TerminalNode DATE() { return getToken(AssignmentStmtParser.DATE, 0); }
		public TerminalNode ALTER() { return getToken(AssignmentStmtParser.ALTER, 0); }
		public TerminalNode DROP() { return getToken(AssignmentStmtParser.DROP, 0); }
		public List<VariablesContext> variables() {
			return getRuleContexts(VariablesContext.class);
		}
		public VariablesContext variables(int i) {
			return getRuleContext(VariablesContext.class,i);
		}
		public TerminalNode DOT() { return getToken(AssignmentStmtParser.DOT, 0); }
		public VariablesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variables; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).enterVariables(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AssignmentStmtListener ) ((AssignmentStmtListener)listener).exitVariables(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof AssignmentStmtVisitor ) return ((AssignmentStmtVisitor<? extends T>)visitor).visitVariables(this);
			else return visitor.visitChildren(this);
		}
	}

	public final VariablesContext variables() throws RecognitionException {
		return variables(0);
	}

	private VariablesContext variables(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		VariablesContext _localctx = new VariablesContext(_ctx, _parentState);
		VariablesContext _prevctx = _localctx;
		int _startState = 18;
		enterRecursionRule(_localctx, 18, RULE_variables, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(198);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				{
				setState(194);
				match(Identifier);
				}
				break;
			case DATE:
				{
				setState(195);
				match(DATE);
				}
				break;
			case ALTER:
				{
				setState(196);
				match(ALTER);
				}
				break;
			case DROP:
				{
				setState(197);
				match(DROP);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(205);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new VariablesContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_variables);
					setState(200);
					if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
					setState(201);
					match(DOT);
					setState(202);
					variables(6);
					}
					} 
				}
				setState(207);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 2:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		case 3:
			return expressionList_sempred((ExpressionListContext)_localctx, predIndex);
		case 9:
			return variables_sempred((VariablesContext)_localctx, predIndex);
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
	private boolean variables_sempred(VariablesContext _localctx, int predIndex) {
		switch (predIndex) {
		case 15:
			return precpred(_ctx, 5);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\u00e8\u00d3\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\3\2\7\2\30\n\2\f\2\16\2\33\13\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\4"+
		"\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4/\n\4\3\4\3\4\3\4\3\4\3\4"+
		"\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4R\n\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\7\4b\n\4\f\4\16\4e\13\4\3\5\3\5"+
		"\3\5\5\5j\n\5\3\5\3\5\3\5\5\5o\n\5\7\5q\n\5\f\5\16\5t\13\5\3\5\3\5\6\5"+
		"x\n\5\r\5\16\5y\3\5\7\5}\n\5\f\5\16\5\u0080\13\5\3\6\3\6\3\6\3\6\3\6\3"+
		"\6\3\6\5\6\u0089\n\6\3\6\3\6\3\6\7\6\u008e\n\6\f\6\16\6\u0091\13\6\3\6"+
		"\3\6\3\6\7\6\u0096\n\6\f\6\16\6\u0099\13\6\3\6\3\6\3\6\3\6\3\6\5\6\u00a0"+
		"\n\6\3\7\3\7\3\7\3\7\6\7\u00a6\n\7\r\7\16\7\u00a7\3\b\3\b\3\b\3\b\5\b"+
		"\u00ae\n\b\3\b\3\b\3\b\5\b\u00b3\n\b\7\b\u00b5\n\b\f\b\16\b\u00b8\13\b"+
		"\3\b\3\b\5\b\u00bc\n\b\3\t\3\t\3\t\3\t\3\n\3\n\3\13\3\13\3\13\3\13\3\13"+
		"\5\13\u00c9\n\13\3\13\3\13\3\13\7\13\u00ce\n\13\f\13\16\13\u00d1\13\13"+
		"\3\13\2\5\6\b\24\f\2\4\6\b\n\f\16\20\22\24\2\n\3\2\13\f\3\2\r\17\3\2\20"+
		"\21\3\2\u00c3\u00c8\3\2\u00ca\u00cf\3\2\u00d1\u00d2\4\2\u00c9\u00c9\u00d0"+
		"\u00d0\4\2\u00d6\u00de\u00e0\u00e0\2\u00f0\2\31\3\2\2\2\4\36\3\2\2\2\6"+
		".\3\2\2\2\bf\3\2\2\2\n\u009f\3\2\2\2\f\u00a5\3\2\2\2\16\u00bb\3\2\2\2"+
		"\20\u00bd\3\2\2\2\22\u00c1\3\2\2\2\24\u00c8\3\2\2\2\26\30\5\4\3\2\27\26"+
		"\3\2\2\2\30\33\3\2\2\2\31\27\3\2\2\2\31\32\3\2\2\2\32\34\3\2\2\2\33\31"+
		"\3\2\2\2\34\35\7\2\2\3\35\3\3\2\2\2\36\37\7\u00df\2\2\37 \7\u00e2\2\2"+
		" !\5\6\4\2!\"\7\3\2\2\"\5\3\2\2\2#$\b\4\1\2$/\5\22\n\2%/\7\u00df\2\2&"+
		"\'\7\4\2\2\'(\5\6\4\2()\7\5\2\2)/\3\2\2\2*+\t\2\2\2+/\5\6\4\16,-\7\u00d3"+
		"\2\2-/\5\6\4\r.#\3\2\2\2.%\3\2\2\2.&\3\2\2\2.*\3\2\2\2.,\3\2\2\2/c\3\2"+
		"\2\2\60\61\f\17\2\2\61\62\7\n\2\2\62b\5\6\4\17\63\64\f\f\2\2\64\65\7\u00d4"+
		"\2\2\65b\5\6\4\r\66\67\f\13\2\2\678\7\u00d5\2\28b\5\6\4\f9:\f\n\2\2:;"+
		"\t\3\2\2;b\5\6\4\13<=\f\t\2\2=>\t\2\2\2>b\5\6\4\n?@\f\b\2\2@A\t\4\2\2"+
		"Ab\5\6\4\tBC\f\7\2\2CD\t\5\2\2Db\5\6\4\bEF\f\6\2\2FG\t\6\2\2Gb\5\6\4\7"+
		"HI\f\4\2\2IJ\t\7\2\2Jb\5\6\4\5KL\f\3\2\2LM\7\u00e2\2\2Mb\5\6\4\3NO\f\22"+
		"\2\2OQ\7\4\2\2PR\5\b\5\2QP\3\2\2\2QR\3\2\2\2RS\3\2\2\2Sb\7\5\2\2TU\f\21"+
		"\2\2UV\7\6\2\2VW\5\6\4\2WX\7\7\2\2Xb\3\2\2\2YZ\f\20\2\2Z[\7\b\2\2[\\\5"+
		"\6\4\2\\]\7\t\2\2]b\3\2\2\2^_\f\5\2\2_`\t\b\2\2`b\5\16\b\2a\60\3\2\2\2"+
		"a\63\3\2\2\2a\66\3\2\2\2a9\3\2\2\2a<\3\2\2\2a?\3\2\2\2aB\3\2\2\2aE\3\2"+
		"\2\2aH\3\2\2\2aK\3\2\2\2aN\3\2\2\2aT\3\2\2\2aY\3\2\2\2a^\3\2\2\2be\3\2"+
		"\2\2ca\3\2\2\2cd\3\2\2\2d\7\3\2\2\2ec\3\2\2\2fi\b\5\1\2gj\5\6\4\2hj\5"+
		"\n\6\2ig\3\2\2\2ih\3\2\2\2jr\3\2\2\2kn\7\u00e3\2\2lo\5\6\4\2mo\5\n\6\2"+
		"nl\3\2\2\2nm\3\2\2\2oq\3\2\2\2pk\3\2\2\2qt\3\2\2\2rp\3\2\2\2rs\3\2\2\2"+
		"s~\3\2\2\2tr\3\2\2\2uw\f\3\2\2vx\7\u00e3\2\2wv\3\2\2\2xy\3\2\2\2yw\3\2"+
		"\2\2yz\3\2\2\2z{\3\2\2\2{}\5\b\5\4|u\3\2\2\2}\u0080\3\2\2\2~|\3\2\2\2"+
		"~\177\3\2\2\2\177\t\3\2\2\2\u0080~\3\2\2\2\u0081\u0082\7\22\2\2\u0082"+
		"\u0083\7\u00df\2\2\u0083\u0084\7\f\2\2\u0084\u0085\7\u00df\2\2\u0085\u008f"+
		"\3\2\2\2\u0086\u0087\7\u00e3\2\2\u0087\u0089\7\22\2\2\u0088\u0086\3\2"+
		"\2\2\u0088\u0089\3\2\2\2\u0089\u008a\3\2\2\2\u008a\u008b\7\u00df\2\2\u008b"+
		"\u008c\7\f\2\2\u008c\u008e\7\u00df\2\2\u008d\u0088\3\2\2\2\u008e\u0091"+
		"\3\2\2\2\u008f\u008d\3\2\2\2\u008f\u0090\3\2\2\2\u0090\u00a0\3\2\2\2\u0091"+
		"\u008f\3\2\2\2\u0092\u0093\7\22\2\2\u0093\u0097\7\u00df\2\2\u0094\u0096"+
		"\7\u00df\2\2\u0095\u0094\3\2\2\2\u0096\u0099\3\2\2\2\u0097\u0095\3\2\2"+
		"\2\u0097\u0098\3\2\2\2\u0098\u00a0\3\2\2\2\u0099\u0097\3\2\2\2\u009a\u009b"+
		"\7\22\2\2\u009b\u009c\7\u00df\2\2\u009c\u009d\7\b\2\2\u009d\u009e\7\r"+
		"\2\2\u009e\u00a0\7\t\2\2\u009f\u0081\3\2\2\2\u009f\u0092\3\2\2\2\u009f"+
		"\u009a\3\2\2\2\u00a0\13\3\2\2\2\u00a1\u00a6\7\u00df\2\2\u00a2\u00a3\7"+
		"\u00df\2\2\u00a3\u00a4\7\f\2\2\u00a4\u00a6\7\u00df\2\2\u00a5\u00a1\3\2"+
		"\2\2\u00a5\u00a2\3\2\2\2\u00a6\u00a7\3\2\2\2\u00a7\u00a5\3\2\2\2\u00a7"+
		"\u00a8\3\2\2\2\u00a8\r\3\2\2\2\u00a9\u00bc\7\u00df\2\2\u00aa\u00ad\7\4"+
		"\2\2\u00ab\u00ae\5\22\n\2\u00ac\u00ae\5\20\t\2\u00ad\u00ab\3\2\2\2\u00ad"+
		"\u00ac\3\2\2\2\u00ae\u00b6\3\2\2\2\u00af\u00b2\7\u00e3\2\2\u00b0\u00b3"+
		"\5\22\n\2\u00b1\u00b3\5\20\t\2\u00b2\u00b0\3\2\2\2\u00b2\u00b1\3\2\2\2"+
		"\u00b3\u00b5\3\2\2\2\u00b4\u00af\3\2\2\2\u00b5\u00b8\3\2\2\2\u00b6\u00b4"+
		"\3\2\2\2\u00b6\u00b7\3\2\2\2\u00b7\u00b9\3\2\2\2\u00b8\u00b6\3\2\2\2\u00b9"+
		"\u00ba\7\5\2\2\u00ba\u00bc\3\2\2\2\u00bb\u00a9\3\2\2\2\u00bb\u00aa\3\2"+
		"\2\2\u00bc\17\3\2\2\2\u00bd\u00be\7\u00dd\2\2\u00be\u00bf\7\23\2\2\u00bf"+
		"\u00c0\7\u00dd\2\2\u00c0\21\3\2\2\2\u00c1\u00c2\t\t\2\2\u00c2\23\3\2\2"+
		"\2\u00c3\u00c4\b\13\1\2\u00c4\u00c9\7\u00df\2\2\u00c5\u00c9\7\u00a6\2"+
		"\2\u00c6\u00c9\7\u008e\2\2\u00c7\u00c9\7\u00ab\2\2\u00c8\u00c3\3\2\2\2"+
		"\u00c8\u00c5\3\2\2\2\u00c8\u00c6\3\2\2\2\u00c8\u00c7\3\2\2\2\u00c9\u00cf"+
		"\3\2\2\2\u00ca\u00cb\f\7\2\2\u00cb\u00cc\7\u00e0\2\2\u00cc\u00ce\5\24"+
		"\13\b\u00cd\u00ca\3\2\2\2\u00ce\u00d1\3\2\2\2\u00cf\u00cd\3\2\2\2\u00cf"+
		"\u00d0\3\2\2\2\u00d0\25\3\2\2\2\u00d1\u00cf\3\2\2\2\30\31.Qacinry~\u0088"+
		"\u008f\u0097\u009f\u00a5\u00a7\u00ad\u00b2\u00b6\u00bb\u00c8\u00cf";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}