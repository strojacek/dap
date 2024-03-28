// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/InfileStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class InfileStmtParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

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
		RULE_infile_main = 0, RULE_infile_stmt = 1, RULE_file_specification = 2, 
		RULE_device_type = 3, RULE_infile_options = 4, RULE_expression = 5, RULE_expressionList = 6, 
		RULE_of_var_list = 7, RULE_identifiers_list = 8, RULE_in_var_list = 9, 
		RULE_colonInts = 10, RULE_literal = 11, RULE_variables = 12;
	private static String[] makeRuleNames() {
		return new String[] {
			"infile_main", "infile_stmt", "file_specification", "device_type", "infile_options", 
			"expression", "expressionList", "of_var_list", "identifiers_list", "in_var_list", 
			"colonInts", "literal", "variables"
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
	public String getGrammarFileName() { return "InfileStmt.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public InfileStmtParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Infile_mainContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(InfileStmtParser.EOF, 0); }
		public List<Infile_stmtContext> infile_stmt() {
			return getRuleContexts(Infile_stmtContext.class);
		}
		public Infile_stmtContext infile_stmt(int i) {
			return getRuleContext(Infile_stmtContext.class,i);
		}
		public Infile_mainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_infile_main; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).enterInfile_main(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).exitInfile_main(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InfileStmtVisitor ) return ((InfileStmtVisitor<? extends T>)visitor).visitInfile_main(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Infile_mainContext infile_main() throws RecognitionException {
		Infile_mainContext _localctx = new Infile_mainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_infile_main);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(29);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==INFILE) {
				{
				{
				setState(26);
				infile_stmt();
				}
				}
				setState(31);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(32);
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

	@SuppressWarnings("CheckReturnValue")
	public static class Infile_stmtContext extends ParserRuleContext {
		public TerminalNode INFILE() { return getToken(InfileStmtParser.INFILE, 0); }
		public File_specificationContext file_specification() {
			return getRuleContext(File_specificationContext.class,0);
		}
		public Device_typeContext device_type() {
			return getRuleContext(Device_typeContext.class,0);
		}
		public List<Infile_optionsContext> infile_options() {
			return getRuleContexts(Infile_optionsContext.class);
		}
		public Infile_optionsContext infile_options(int i) {
			return getRuleContext(Infile_optionsContext.class,i);
		}
		public Infile_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_infile_stmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).enterInfile_stmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).exitInfile_stmt(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InfileStmtVisitor ) return ((InfileStmtVisitor<? extends T>)visitor).visitInfile_stmt(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Infile_stmtContext infile_stmt() throws RecognitionException {
		Infile_stmtContext _localctx = new Infile_stmtContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_infile_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(34);
			match(INFILE);
			setState(35);
			file_specification();
			setState(37);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 141)) & ~0x3f) == 0 && ((1L << (_la - 141)) & 1023L) != 0)) {
				{
				setState(36);
				device_type();
				}
			}

			setState(42);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 151)) & ~0x3f) == 0 && ((1L << (_la - 151)) & 4095L) != 0) || _la==Identifier) {
				{
				{
				setState(39);
				infile_options();
				}
				}
				setState(44);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(45);
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

	@SuppressWarnings("CheckReturnValue")
	public static class File_specificationContext extends ParserRuleContext {
		public TerminalNode STRINGLITERAL() { return getToken(InfileStmtParser.STRINGLITERAL, 0); }
		public TerminalNode Identifier() { return getToken(InfileStmtParser.Identifier, 0); }
		public TerminalNode CARDS() { return getToken(InfileStmtParser.CARDS, 0); }
		public TerminalNode CARDS4() { return getToken(InfileStmtParser.CARDS4, 0); }
		public TerminalNode DATALINES() { return getToken(InfileStmtParser.DATALINES, 0); }
		public TerminalNode DATALINES4() { return getToken(InfileStmtParser.DATALINES4, 0); }
		public File_specificationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_file_specification; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).enterFile_specification(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).exitFile_specification(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InfileStmtVisitor ) return ((InfileStmtVisitor<? extends T>)visitor).visitFile_specification(this);
			else return visitor.visitChildren(this);
		}
	}

	public final File_specificationContext file_specification() throws RecognitionException {
		File_specificationContext _localctx = new File_specificationContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_file_specification);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(47);
			_la = _input.LA(1);
			if ( !(((((_la - 133)) & ~0x3f) == 0 && ((1L << (_la - 133)) & 27L) != 0) || _la==STRINGLITERAL || _la==Identifier) ) {
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

	@SuppressWarnings("CheckReturnValue")
	public static class Device_typeContext extends ParserRuleContext {
		public TerminalNode DISK() { return getToken(InfileStmtParser.DISK, 0); }
		public TerminalNode DUMMY() { return getToken(InfileStmtParser.DUMMY, 0); }
		public TerminalNode GTERM() { return getToken(InfileStmtParser.GTERM, 0); }
		public TerminalNode PIPE() { return getToken(InfileStmtParser.PIPE, 0); }
		public TerminalNode PLOTTER() { return getToken(InfileStmtParser.PLOTTER, 0); }
		public TerminalNode PRINTER() { return getToken(InfileStmtParser.PRINTER, 0); }
		public TerminalNode TAPE() { return getToken(InfileStmtParser.TAPE, 0); }
		public TerminalNode TEMP() { return getToken(InfileStmtParser.TEMP, 0); }
		public TerminalNode TERMINAL() { return getToken(InfileStmtParser.TERMINAL, 0); }
		public TerminalNode UPRINTER() { return getToken(InfileStmtParser.UPRINTER, 0); }
		public Device_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_device_type; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).enterDevice_type(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).exitDevice_type(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InfileStmtVisitor ) return ((InfileStmtVisitor<? extends T>)visitor).visitDevice_type(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Device_typeContext device_type() throws RecognitionException {
		Device_typeContext _localctx = new Device_typeContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_device_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(49);
			_la = _input.LA(1);
			if ( !(((((_la - 141)) & ~0x3f) == 0 && ((1L << (_la - 141)) & 1023L) != 0)) ) {
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

	@SuppressWarnings("CheckReturnValue")
	public static class Infile_optionsContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(InfileStmtParser.Identifier, 0); }
		public TerminalNode EQUAL() { return getToken(InfileStmtParser.EQUAL, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode DSD() { return getToken(InfileStmtParser.DSD, 0); }
		public TerminalNode EXPANDTABS() { return getToken(InfileStmtParser.EXPANDTABS, 0); }
		public TerminalNode NOEXPANDTABS() { return getToken(InfileStmtParser.NOEXPANDTABS, 0); }
		public TerminalNode FLOWOVER() { return getToken(InfileStmtParser.FLOWOVER, 0); }
		public TerminalNode MISSOVER() { return getToken(InfileStmtParser.MISSOVER, 0); }
		public TerminalNode PAD() { return getToken(InfileStmtParser.PAD, 0); }
		public TerminalNode NOPAD() { return getToken(InfileStmtParser.NOPAD, 0); }
		public TerminalNode SCANOVER() { return getToken(InfileStmtParser.SCANOVER, 0); }
		public TerminalNode SHAREBUFFERS() { return getToken(InfileStmtParser.SHAREBUFFERS, 0); }
		public TerminalNode STOPOVER() { return getToken(InfileStmtParser.STOPOVER, 0); }
		public TerminalNode TRUNCOVER() { return getToken(InfileStmtParser.TRUNCOVER, 0); }
		public TerminalNode V_INFILE_() { return getToken(InfileStmtParser.V_INFILE_, 0); }
		public Infile_optionsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_infile_options; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).enterInfile_options(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).exitInfile_options(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InfileStmtVisitor ) return ((InfileStmtVisitor<? extends T>)visitor).visitInfile_options(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Infile_optionsContext infile_options() throws RecognitionException {
		Infile_optionsContext _localctx = new Infile_optionsContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_infile_options);
		try {
			setState(66);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(51);
				match(Identifier);
				setState(52);
				match(EQUAL);
				setState(53);
				expression(0);
				}
				break;
			case DSD:
				enterOuterAlt(_localctx, 2);
				{
				setState(54);
				match(DSD);
				}
				break;
			case EXPANDTABS:
				enterOuterAlt(_localctx, 3);
				{
				setState(55);
				match(EXPANDTABS);
				}
				break;
			case NOEXPANDTABS:
				enterOuterAlt(_localctx, 4);
				{
				setState(56);
				match(NOEXPANDTABS);
				}
				break;
			case FLOWOVER:
				enterOuterAlt(_localctx, 5);
				{
				setState(57);
				match(FLOWOVER);
				}
				break;
			case MISSOVER:
				enterOuterAlt(_localctx, 6);
				{
				setState(58);
				match(MISSOVER);
				}
				break;
			case PAD:
				enterOuterAlt(_localctx, 7);
				{
				setState(59);
				match(PAD);
				}
				break;
			case NOPAD:
				enterOuterAlt(_localctx, 8);
				{
				setState(60);
				match(NOPAD);
				}
				break;
			case SCANOVER:
				enterOuterAlt(_localctx, 9);
				{
				setState(61);
				match(SCANOVER);
				}
				break;
			case SHAREBUFFERS:
				enterOuterAlt(_localctx, 10);
				{
				setState(62);
				match(SHAREBUFFERS);
				}
				break;
			case STOPOVER:
				enterOuterAlt(_localctx, 11);
				{
				setState(63);
				match(STOPOVER);
				}
				break;
			case TRUNCOVER:
				enterOuterAlt(_localctx, 12);
				{
				setState(64);
				match(TRUNCOVER);
				}
				break;
			case V_INFILE_:
				enterOuterAlt(_localctx, 13);
				{
				setState(65);
				match(V_INFILE_);
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

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(InfileStmtParser.Identifier, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode NOT() { return getToken(InfileStmtParser.NOT, 0); }
		public TerminalNode MIN() { return getToken(InfileStmtParser.MIN, 0); }
		public TerminalNode MAX() { return getToken(InfileStmtParser.MAX, 0); }
		public TerminalNode EQ() { return getToken(InfileStmtParser.EQ, 0); }
		public TerminalNode NE() { return getToken(InfileStmtParser.NE, 0); }
		public TerminalNode GT() { return getToken(InfileStmtParser.GT, 0); }
		public TerminalNode LT() { return getToken(InfileStmtParser.LT, 0); }
		public TerminalNode GE() { return getToken(InfileStmtParser.GE, 0); }
		public TerminalNode LE() { return getToken(InfileStmtParser.LE, 0); }
		public TerminalNode EQC() { return getToken(InfileStmtParser.EQC, 0); }
		public TerminalNode NEC() { return getToken(InfileStmtParser.NEC, 0); }
		public TerminalNode GTC() { return getToken(InfileStmtParser.GTC, 0); }
		public TerminalNode LTC() { return getToken(InfileStmtParser.LTC, 0); }
		public TerminalNode GEC() { return getToken(InfileStmtParser.GEC, 0); }
		public TerminalNode LEC() { return getToken(InfileStmtParser.LEC, 0); }
		public TerminalNode AND() { return getToken(InfileStmtParser.AND, 0); }
		public TerminalNode OR() { return getToken(InfileStmtParser.OR, 0); }
		public TerminalNode EQUAL() { return getToken(InfileStmtParser.EQUAL, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public In_var_listContext in_var_list() {
			return getRuleContext(In_var_listContext.class,0);
		}
		public TerminalNode IN() { return getToken(InfileStmtParser.IN, 0); }
		public TerminalNode INColon() { return getToken(InfileStmtParser.INColon, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).exitExpression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InfileStmtVisitor ) return ((InfileStmtVisitor<? extends T>)visitor).visitExpression(this);
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
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(79);
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
				setState(69);
				literal();
				}
				break;
			case Identifier:
				{
				setState(70);
				match(Identifier);
				}
				break;
			case T__1:
				{
				setState(71);
				match(T__1);
				setState(72);
				expression(0);
				setState(73);
				match(T__2);
				}
				break;
			case T__8:
			case T__9:
				{
				setState(75);
				_la = _input.LA(1);
				if ( !(_la==T__8 || _la==T__9) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(76);
				expression(12);
				}
				break;
			case NOT:
				{
				setState(77);
				match(NOT);
				setState(78);
				expression(11);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(132);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(130);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(81);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(82);
						match(T__7);
						setState(83);
						expression(13);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(84);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(85);
						match(MIN);
						setState(86);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(87);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(88);
						match(MAX);
						setState(89);
						expression(10);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(90);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(91);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 14336L) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(92);
						expression(9);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(93);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(94);
						_la = _input.LA(1);
						if ( !(_la==T__8 || _la==T__9) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(95);
						expression(8);
						}
						break;
					case 6:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(96);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(97);
						_la = _input.LA(1);
						if ( !(_la==T__13 || _la==T__14) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(98);
						expression(7);
						}
						break;
					case 7:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(99);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(100);
						_la = _input.LA(1);
						if ( !(((((_la - 193)) & ~0x3f) == 0 && ((1L << (_la - 193)) & 63L) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(101);
						expression(6);
						}
						break;
					case 8:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(102);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(103);
						_la = _input.LA(1);
						if ( !(((((_la - 200)) & ~0x3f) == 0 && ((1L << (_la - 200)) & 63L) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(104);
						expression(5);
						}
						break;
					case 9:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(105);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(106);
						_la = _input.LA(1);
						if ( !(_la==AND || _la==OR) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(107);
						expression(3);
						}
						break;
					case 10:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(108);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(109);
						match(EQUAL);
						setState(110);
						expression(1);
						}
						break;
					case 11:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(111);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(112);
						match(T__1);
						setState(114);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 67076L) != 0) || ((((_la - 209)) & ~0x3f) == 0 && ((1L << (_la - 209)) & 16377L) != 0)) {
							{
							setState(113);
							expressionList(0);
							}
						}

						setState(116);
						match(T__2);
						}
						break;
					case 12:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(117);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(118);
						match(T__3);
						setState(119);
						expression(0);
						setState(120);
						match(T__4);
						}
						break;
					case 13:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(122);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(123);
						match(T__5);
						setState(124);
						expression(0);
						setState(125);
						match(T__6);
						}
						break;
					case 14:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(127);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(128);
						_la = _input.LA(1);
						if ( !(_la==IN || _la==INColon) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(129);
						in_var_list();
						}
						break;
					}
					} 
				}
				setState(134);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
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

	@SuppressWarnings("CheckReturnValue")
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
		public List<TerminalNode> COMMA() { return getTokens(InfileStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(InfileStmtParser.COMMA, i);
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
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).enterExpressionList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).exitExpressionList(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InfileStmtVisitor ) return ((InfileStmtVisitor<? extends T>)visitor).visitExpressionList(this);
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
		int _startState = 12;
		enterRecursionRule(_localctx, 12, RULE_expressionList, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(138);
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
				setState(136);
				expression(0);
				}
				break;
			case T__15:
				{
				setState(137);
				of_var_list();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(147);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(140);
					match(COMMA);
					setState(143);
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
						setState(141);
						expression(0);
						}
						break;
					case T__15:
						{
						setState(142);
						of_var_list();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					} 
				}
				setState(149);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			}
			}
			_ctx.stop = _input.LT(-1);
			setState(159);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ExpressionListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_expressionList);
					setState(150);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(152); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(151);
						match(COMMA);
						}
						}
						setState(154); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==COMMA );
					setState(156);
					expressionList(2);
					}
					} 
				}
				setState(161);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
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

	@SuppressWarnings("CheckReturnValue")
	public static class Of_var_listContext extends ParserRuleContext {
		public List<TerminalNode> Identifier() { return getTokens(InfileStmtParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(InfileStmtParser.Identifier, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(InfileStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(InfileStmtParser.COMMA, i);
		}
		public Of_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_of_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).enterOf_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).exitOf_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InfileStmtVisitor ) return ((InfileStmtVisitor<? extends T>)visitor).visitOf_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Of_var_listContext of_var_list() throws RecognitionException {
		Of_var_listContext _localctx = new Of_var_listContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_of_var_list);
		int _la;
		try {
			int _alt;
			setState(192);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(162);
				match(T__15);
				{
				setState(163);
				match(Identifier);
				setState(164);
				match(T__9);
				setState(165);
				match(Identifier);
				}
				setState(176);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(169);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==COMMA) {
							{
							setState(167);
							match(COMMA);
							setState(168);
							match(T__15);
							}
						}

						{
						setState(171);
						match(Identifier);
						setState(172);
						match(T__9);
						setState(173);
						match(Identifier);
						}
						}
						} 
					}
					setState(178);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(179);
				match(T__15);
				setState(180);
				match(Identifier);
				setState(184);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(181);
						match(Identifier);
						}
						} 
					}
					setState(186);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(187);
				match(T__15);
				setState(188);
				match(Identifier);
				setState(189);
				match(T__5);
				setState(190);
				match(T__10);
				setState(191);
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

	@SuppressWarnings("CheckReturnValue")
	public static class Identifiers_listContext extends ParserRuleContext {
		public List<TerminalNode> Identifier() { return getTokens(InfileStmtParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(InfileStmtParser.Identifier, i);
		}
		public Identifiers_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifiers_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).enterIdentifiers_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).exitIdentifiers_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InfileStmtVisitor ) return ((InfileStmtVisitor<? extends T>)visitor).visitIdentifiers_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Identifiers_listContext identifiers_list() throws RecognitionException {
		Identifiers_listContext _localctx = new Identifiers_listContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_identifiers_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(198); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(198);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
				case 1:
					{
					setState(194);
					match(Identifier);
					}
					break;
				case 2:
					{
					setState(195);
					match(Identifier);
					setState(196);
					match(T__9);
					setState(197);
					match(Identifier);
					}
					break;
				}
				}
				setState(200); 
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

	@SuppressWarnings("CheckReturnValue")
	public static class In_var_listContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(InfileStmtParser.Identifier, 0); }
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
		public List<TerminalNode> COMMA() { return getTokens(InfileStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(InfileStmtParser.COMMA, i);
		}
		public In_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_in_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).enterIn_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).exitIn_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InfileStmtVisitor ) return ((InfileStmtVisitor<? extends T>)visitor).visitIn_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final In_var_listContext in_var_list() throws RecognitionException {
		In_var_listContext _localctx = new In_var_listContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_in_var_list);
		int _la;
		try {
			setState(220);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(202);
				match(Identifier);
				}
				break;
			case T__1:
				enterOuterAlt(_localctx, 2);
				{
				setState(203);
				match(T__1);
				setState(206);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
				case 1:
					{
					setState(204);
					literal();
					}
					break;
				case 2:
					{
					setState(205);
					colonInts();
					}
					break;
				}
				setState(215);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(208);
					match(COMMA);
					setState(211);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
					case 1:
						{
						setState(209);
						literal();
						}
						break;
					case 2:
						{
						setState(210);
						colonInts();
						}
						break;
					}
					}
					}
					setState(217);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(218);
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

	@SuppressWarnings("CheckReturnValue")
	public static class ColonIntsContext extends ParserRuleContext {
		public List<TerminalNode> INT() { return getTokens(InfileStmtParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(InfileStmtParser.INT, i);
		}
		public ColonIntsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_colonInts; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).enterColonInts(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).exitColonInts(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InfileStmtVisitor ) return ((InfileStmtVisitor<? extends T>)visitor).visitColonInts(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ColonIntsContext colonInts() throws RecognitionException {
		ColonIntsContext _localctx = new ColonIntsContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_colonInts);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(222);
			match(INT);
			setState(223);
			match(T__16);
			setState(224);
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

	@SuppressWarnings("CheckReturnValue")
	public static class LiteralContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(InfileStmtParser.INT, 0); }
		public TerminalNode FloatingPointLiteral() { return getToken(InfileStmtParser.FloatingPointLiteral, 0); }
		public TerminalNode STRINGLITERAL() { return getToken(InfileStmtParser.STRINGLITERAL, 0); }
		public TerminalNode DateLiteral() { return getToken(InfileStmtParser.DateLiteral, 0); }
		public TerminalNode TimeLiteral() { return getToken(InfileStmtParser.TimeLiteral, 0); }
		public TerminalNode DateTimeLiteral() { return getToken(InfileStmtParser.DateTimeLiteral, 0); }
		public TerminalNode BitLiteral() { return getToken(InfileStmtParser.BitLiteral, 0); }
		public TerminalNode NameLiteral() { return getToken(InfileStmtParser.NameLiteral, 0); }
		public TerminalNode HexLiteral() { return getToken(InfileStmtParser.HexLiteral, 0); }
		public TerminalNode DOT() { return getToken(InfileStmtParser.DOT, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).enterLiteral(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).exitLiteral(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InfileStmtVisitor ) return ((InfileStmtVisitor<? extends T>)visitor).visitLiteral(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(226);
			_la = _input.LA(1);
			if ( !(((((_la - 212)) & ~0x3f) == 0 && ((1L << (_la - 212)) & 1535L) != 0)) ) {
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

	@SuppressWarnings("CheckReturnValue")
	public static class VariablesContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(InfileStmtParser.Identifier, 0); }
		public TerminalNode DATE() { return getToken(InfileStmtParser.DATE, 0); }
		public TerminalNode ALTER() { return getToken(InfileStmtParser.ALTER, 0); }
		public TerminalNode DROP() { return getToken(InfileStmtParser.DROP, 0); }
		public List<VariablesContext> variables() {
			return getRuleContexts(VariablesContext.class);
		}
		public VariablesContext variables(int i) {
			return getRuleContext(VariablesContext.class,i);
		}
		public TerminalNode DOT() { return getToken(InfileStmtParser.DOT, 0); }
		public VariablesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variables; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).enterVariables(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InfileStmtListener ) ((InfileStmtListener)listener).exitVariables(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof InfileStmtVisitor ) return ((InfileStmtVisitor<? extends T>)visitor).visitVariables(this);
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
		int _startState = 24;
		enterRecursionRule(_localctx, 24, RULE_variables, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(233);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				{
				setState(229);
				match(Identifier);
				}
				break;
			case DATE:
				{
				setState(230);
				match(DATE);
				}
				break;
			case ALTER:
				{
				setState(231);
				match(ALTER);
				}
				break;
			case DROP:
				{
				setState(232);
				match(DROP);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(240);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new VariablesContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_variables);
					setState(235);
					if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
					setState(236);
					match(DOT);
					setState(237);
					variables(6);
					}
					} 
				}
				setState(242);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
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
		case 5:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		case 6:
			return expressionList_sempred((ExpressionListContext)_localctx, predIndex);
		case 12:
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
		"\u0004\u0001\u00e6\u00f4\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001"+
		"\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004"+
		"\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007"+
		"\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b"+
		"\u0002\f\u0007\f\u0001\u0000\u0005\u0000\u001c\b\u0000\n\u0000\f\u0000"+
		"\u001f\t\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0003\u0001&\b\u0001\u0001\u0001\u0005\u0001)\b\u0001\n\u0001\f\u0001"+
		",\t\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0003"+
		"\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004C\b\u0004"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u0005"+
		"P\b\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u0005s\b\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0005\u0005\u0083\b\u0005\n\u0005\f\u0005\u0086"+
		"\t\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0003\u0006\u008b\b\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0003\u0006\u0090\b\u0006\u0005\u0006"+
		"\u0092\b\u0006\n\u0006\f\u0006\u0095\t\u0006\u0001\u0006\u0001\u0006\u0004"+
		"\u0006\u0099\b\u0006\u000b\u0006\f\u0006\u009a\u0001\u0006\u0005\u0006"+
		"\u009e\b\u0006\n\u0006\f\u0006\u00a1\t\u0006\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007\u00aa"+
		"\b\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0005\u0007\u00af\b\u0007"+
		"\n\u0007\f\u0007\u00b2\t\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0005"+
		"\u0007\u00b7\b\u0007\n\u0007\f\u0007\u00ba\t\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007\u00c1\b\u0007\u0001\b"+
		"\u0001\b\u0001\b\u0001\b\u0004\b\u00c7\b\b\u000b\b\f\b\u00c8\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0003\t\u00cf\b\t\u0001\t\u0001\t\u0001\t\u0003\t\u00d4"+
		"\b\t\u0005\t\u00d6\b\t\n\t\f\t\u00d9\t\t\u0001\t\u0001\t\u0003\t\u00dd"+
		"\b\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0003\f\u00ea\b\f\u0001\f\u0001\f\u0001\f\u0005"+
		"\f\u00ef\b\f\n\f\f\f\u00f2\t\f\u0001\f\u0000\u0003\n\f\u0018\r\u0000\u0002"+
		"\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u0000\n\u0004\u0000"+
		"\u0085\u0086\u0088\u0089\u00da\u00da\u00dd\u00dd\u0001\u0000\u008d\u0096"+
		"\u0001\u0000\t\n\u0001\u0000\u000b\r\u0001\u0000\u000e\u000f\u0001\u0000"+
		"\u00c1\u00c6\u0001\u0000\u00c8\u00cd\u0001\u0000\u00cf\u00d0\u0002\u0000"+
		"\u00c7\u00c7\u00ce\u00ce\u0002\u0000\u00d4\u00dc\u00de\u00de\u011c\u0000"+
		"\u001d\u0001\u0000\u0000\u0000\u0002\"\u0001\u0000\u0000\u0000\u0004/"+
		"\u0001\u0000\u0000\u0000\u00061\u0001\u0000\u0000\u0000\bB\u0001\u0000"+
		"\u0000\u0000\nO\u0001\u0000\u0000\u0000\f\u0087\u0001\u0000\u0000\u0000"+
		"\u000e\u00c0\u0001\u0000\u0000\u0000\u0010\u00c6\u0001\u0000\u0000\u0000"+
		"\u0012\u00dc\u0001\u0000\u0000\u0000\u0014\u00de\u0001\u0000\u0000\u0000"+
		"\u0016\u00e2\u0001\u0000\u0000\u0000\u0018\u00e9\u0001\u0000\u0000\u0000"+
		"\u001a\u001c\u0003\u0002\u0001\u0000\u001b\u001a\u0001\u0000\u0000\u0000"+
		"\u001c\u001f\u0001\u0000\u0000\u0000\u001d\u001b\u0001\u0000\u0000\u0000"+
		"\u001d\u001e\u0001\u0000\u0000\u0000\u001e \u0001\u0000\u0000\u0000\u001f"+
		"\u001d\u0001\u0000\u0000\u0000 !\u0005\u0000\u0000\u0001!\u0001\u0001"+
		"\u0000\u0000\u0000\"#\u0005E\u0000\u0000#%\u0003\u0004\u0002\u0000$&\u0003"+
		"\u0006\u0003\u0000%$\u0001\u0000\u0000\u0000%&\u0001\u0000\u0000\u0000"+
		"&*\u0001\u0000\u0000\u0000\')\u0003\b\u0004\u0000(\'\u0001\u0000\u0000"+
		"\u0000),\u0001\u0000\u0000\u0000*(\u0001\u0000\u0000\u0000*+\u0001\u0000"+
		"\u0000\u0000+-\u0001\u0000\u0000\u0000,*\u0001\u0000\u0000\u0000-.\u0005"+
		"\u0001\u0000\u0000.\u0003\u0001\u0000\u0000\u0000/0\u0007\u0000\u0000"+
		"\u00000\u0005\u0001\u0000\u0000\u000012\u0007\u0001\u0000\u00002\u0007"+
		"\u0001\u0000\u0000\u000034\u0005\u00dd\u0000\u000045\u0005\u00e0\u0000"+
		"\u00005C\u0003\n\u0005\u00006C\u0005\u0097\u0000\u00007C\u0005\u0098\u0000"+
		"\u00008C\u0005\u0099\u0000\u00009C\u0005\u009a\u0000\u0000:C\u0005\u009b"+
		"\u0000\u0000;C\u0005\u009c\u0000\u0000<C\u0005\u009d\u0000\u0000=C\u0005"+
		"\u009e\u0000\u0000>C\u0005\u009f\u0000\u0000?C\u0005\u00a0\u0000\u0000"+
		"@C\u0005\u00a1\u0000\u0000AC\u0005\u00a2\u0000\u0000B3\u0001\u0000\u0000"+
		"\u0000B6\u0001\u0000\u0000\u0000B7\u0001\u0000\u0000\u0000B8\u0001\u0000"+
		"\u0000\u0000B9\u0001\u0000\u0000\u0000B:\u0001\u0000\u0000\u0000B;\u0001"+
		"\u0000\u0000\u0000B<\u0001\u0000\u0000\u0000B=\u0001\u0000\u0000\u0000"+
		"B>\u0001\u0000\u0000\u0000B?\u0001\u0000\u0000\u0000B@\u0001\u0000\u0000"+
		"\u0000BA\u0001\u0000\u0000\u0000C\t\u0001\u0000\u0000\u0000DE\u0006\u0005"+
		"\uffff\uffff\u0000EP\u0003\u0016\u000b\u0000FP\u0005\u00dd\u0000\u0000"+
		"GH\u0005\u0002\u0000\u0000HI\u0003\n\u0005\u0000IJ\u0005\u0003\u0000\u0000"+
		"JP\u0001\u0000\u0000\u0000KL\u0007\u0002\u0000\u0000LP\u0003\n\u0005\f"+
		"MN\u0005\u00d1\u0000\u0000NP\u0003\n\u0005\u000bOD\u0001\u0000\u0000\u0000"+
		"OF\u0001\u0000\u0000\u0000OG\u0001\u0000\u0000\u0000OK\u0001\u0000\u0000"+
		"\u0000OM\u0001\u0000\u0000\u0000P\u0084\u0001\u0000\u0000\u0000QR\n\r"+
		"\u0000\u0000RS\u0005\b\u0000\u0000S\u0083\u0003\n\u0005\rTU\n\n\u0000"+
		"\u0000UV\u0005\u00d2\u0000\u0000V\u0083\u0003\n\u0005\u000bWX\n\t\u0000"+
		"\u0000XY\u0005\u00d3\u0000\u0000Y\u0083\u0003\n\u0005\nZ[\n\b\u0000\u0000"+
		"[\\\u0007\u0003\u0000\u0000\\\u0083\u0003\n\u0005\t]^\n\u0007\u0000\u0000"+
		"^_\u0007\u0002\u0000\u0000_\u0083\u0003\n\u0005\b`a\n\u0006\u0000\u0000"+
		"ab\u0007\u0004\u0000\u0000b\u0083\u0003\n\u0005\u0007cd\n\u0005\u0000"+
		"\u0000de\u0007\u0005\u0000\u0000e\u0083\u0003\n\u0005\u0006fg\n\u0004"+
		"\u0000\u0000gh\u0007\u0006\u0000\u0000h\u0083\u0003\n\u0005\u0005ij\n"+
		"\u0002\u0000\u0000jk\u0007\u0007\u0000\u0000k\u0083\u0003\n\u0005\u0003"+
		"lm\n\u0001\u0000\u0000mn\u0005\u00e0\u0000\u0000n\u0083\u0003\n\u0005"+
		"\u0001op\n\u0010\u0000\u0000pr\u0005\u0002\u0000\u0000qs\u0003\f\u0006"+
		"\u0000rq\u0001\u0000\u0000\u0000rs\u0001\u0000\u0000\u0000st\u0001\u0000"+
		"\u0000\u0000t\u0083\u0005\u0003\u0000\u0000uv\n\u000f\u0000\u0000vw\u0005"+
		"\u0004\u0000\u0000wx\u0003\n\u0005\u0000xy\u0005\u0005\u0000\u0000y\u0083"+
		"\u0001\u0000\u0000\u0000z{\n\u000e\u0000\u0000{|\u0005\u0006\u0000\u0000"+
		"|}\u0003\n\u0005\u0000}~\u0005\u0007\u0000\u0000~\u0083\u0001\u0000\u0000"+
		"\u0000\u007f\u0080\n\u0003\u0000\u0000\u0080\u0081\u0007\b\u0000\u0000"+
		"\u0081\u0083\u0003\u0012\t\u0000\u0082Q\u0001\u0000\u0000\u0000\u0082"+
		"T\u0001\u0000\u0000\u0000\u0082W\u0001\u0000\u0000\u0000\u0082Z\u0001"+
		"\u0000\u0000\u0000\u0082]\u0001\u0000\u0000\u0000\u0082`\u0001\u0000\u0000"+
		"\u0000\u0082c\u0001\u0000\u0000\u0000\u0082f\u0001\u0000\u0000\u0000\u0082"+
		"i\u0001\u0000\u0000\u0000\u0082l\u0001\u0000\u0000\u0000\u0082o\u0001"+
		"\u0000\u0000\u0000\u0082u\u0001\u0000\u0000\u0000\u0082z\u0001\u0000\u0000"+
		"\u0000\u0082\u007f\u0001\u0000\u0000\u0000\u0083\u0086\u0001\u0000\u0000"+
		"\u0000\u0084\u0082\u0001\u0000\u0000\u0000\u0084\u0085\u0001\u0000\u0000"+
		"\u0000\u0085\u000b\u0001\u0000\u0000\u0000\u0086\u0084\u0001\u0000\u0000"+
		"\u0000\u0087\u008a\u0006\u0006\uffff\uffff\u0000\u0088\u008b\u0003\n\u0005"+
		"\u0000\u0089\u008b\u0003\u000e\u0007\u0000\u008a\u0088\u0001\u0000\u0000"+
		"\u0000\u008a\u0089\u0001\u0000\u0000\u0000\u008b\u0093\u0001\u0000\u0000"+
		"\u0000\u008c\u008f\u0005\u00e1\u0000\u0000\u008d\u0090\u0003\n\u0005\u0000"+
		"\u008e\u0090\u0003\u000e\u0007\u0000\u008f\u008d\u0001\u0000\u0000\u0000"+
		"\u008f\u008e\u0001\u0000\u0000\u0000\u0090\u0092\u0001\u0000\u0000\u0000"+
		"\u0091\u008c\u0001\u0000\u0000\u0000\u0092\u0095\u0001\u0000\u0000\u0000"+
		"\u0093\u0091\u0001\u0000\u0000\u0000\u0093\u0094\u0001\u0000\u0000\u0000"+
		"\u0094\u009f\u0001\u0000\u0000\u0000\u0095\u0093\u0001\u0000\u0000\u0000"+
		"\u0096\u0098\n\u0001\u0000\u0000\u0097\u0099\u0005\u00e1\u0000\u0000\u0098"+
		"\u0097\u0001\u0000\u0000\u0000\u0099\u009a\u0001\u0000\u0000\u0000\u009a"+
		"\u0098\u0001\u0000\u0000\u0000\u009a\u009b\u0001\u0000\u0000\u0000\u009b"+
		"\u009c\u0001\u0000\u0000\u0000\u009c\u009e\u0003\f\u0006\u0002\u009d\u0096"+
		"\u0001\u0000\u0000\u0000\u009e\u00a1\u0001\u0000\u0000\u0000\u009f\u009d"+
		"\u0001\u0000\u0000\u0000\u009f\u00a0\u0001\u0000\u0000\u0000\u00a0\r\u0001"+
		"\u0000\u0000\u0000\u00a1\u009f\u0001\u0000\u0000\u0000\u00a2\u00a3\u0005"+
		"\u0010\u0000\u0000\u00a3\u00a4\u0005\u00dd\u0000\u0000\u00a4\u00a5\u0005"+
		"\n\u0000\u0000\u00a5\u00a6\u0005\u00dd\u0000\u0000\u00a6\u00b0\u0001\u0000"+
		"\u0000\u0000\u00a7\u00a8\u0005\u00e1\u0000\u0000\u00a8\u00aa\u0005\u0010"+
		"\u0000\u0000\u00a9\u00a7\u0001\u0000\u0000\u0000\u00a9\u00aa\u0001\u0000"+
		"\u0000\u0000\u00aa\u00ab\u0001\u0000\u0000\u0000\u00ab\u00ac\u0005\u00dd"+
		"\u0000\u0000\u00ac\u00ad\u0005\n\u0000\u0000\u00ad\u00af\u0005\u00dd\u0000"+
		"\u0000\u00ae\u00a9\u0001\u0000\u0000\u0000\u00af\u00b2\u0001\u0000\u0000"+
		"\u0000\u00b0\u00ae\u0001\u0000\u0000\u0000\u00b0\u00b1\u0001\u0000\u0000"+
		"\u0000\u00b1\u00c1\u0001\u0000\u0000\u0000\u00b2\u00b0\u0001\u0000\u0000"+
		"\u0000\u00b3\u00b4\u0005\u0010\u0000\u0000\u00b4\u00b8\u0005\u00dd\u0000"+
		"\u0000\u00b5\u00b7\u0005\u00dd\u0000\u0000\u00b6\u00b5\u0001\u0000\u0000"+
		"\u0000\u00b7\u00ba\u0001\u0000\u0000\u0000\u00b8\u00b6\u0001\u0000\u0000"+
		"\u0000\u00b8\u00b9\u0001\u0000\u0000\u0000\u00b9\u00c1\u0001\u0000\u0000"+
		"\u0000\u00ba\u00b8\u0001\u0000\u0000\u0000\u00bb\u00bc\u0005\u0010\u0000"+
		"\u0000\u00bc\u00bd\u0005\u00dd\u0000\u0000\u00bd\u00be\u0005\u0006\u0000"+
		"\u0000\u00be\u00bf\u0005\u000b\u0000\u0000\u00bf\u00c1\u0005\u0007\u0000"+
		"\u0000\u00c0\u00a2\u0001\u0000\u0000\u0000\u00c0\u00b3\u0001\u0000\u0000"+
		"\u0000\u00c0\u00bb\u0001\u0000\u0000\u0000\u00c1\u000f\u0001\u0000\u0000"+
		"\u0000\u00c2\u00c7\u0005\u00dd\u0000\u0000\u00c3\u00c4\u0005\u00dd\u0000"+
		"\u0000\u00c4\u00c5\u0005\n\u0000\u0000\u00c5\u00c7\u0005\u00dd\u0000\u0000"+
		"\u00c6\u00c2\u0001\u0000\u0000\u0000\u00c6\u00c3\u0001\u0000\u0000\u0000"+
		"\u00c7\u00c8\u0001\u0000\u0000\u0000\u00c8\u00c6\u0001\u0000\u0000\u0000"+
		"\u00c8\u00c9\u0001\u0000\u0000\u0000\u00c9\u0011\u0001\u0000\u0000\u0000"+
		"\u00ca\u00dd\u0005\u00dd\u0000\u0000\u00cb\u00ce\u0005\u0002\u0000\u0000"+
		"\u00cc\u00cf\u0003\u0016\u000b\u0000\u00cd\u00cf\u0003\u0014\n\u0000\u00ce"+
		"\u00cc\u0001\u0000\u0000\u0000\u00ce\u00cd\u0001\u0000\u0000\u0000\u00cf"+
		"\u00d7\u0001\u0000\u0000\u0000\u00d0\u00d3\u0005\u00e1\u0000\u0000\u00d1"+
		"\u00d4\u0003\u0016\u000b\u0000\u00d2\u00d4\u0003\u0014\n\u0000\u00d3\u00d1"+
		"\u0001\u0000\u0000\u0000\u00d3\u00d2\u0001\u0000\u0000\u0000\u00d4\u00d6"+
		"\u0001\u0000\u0000\u0000\u00d5\u00d0\u0001\u0000\u0000\u0000\u00d6\u00d9"+
		"\u0001\u0000\u0000\u0000\u00d7\u00d5\u0001\u0000\u0000\u0000\u00d7\u00d8"+
		"\u0001\u0000\u0000\u0000\u00d8\u00da\u0001\u0000\u0000\u0000\u00d9\u00d7"+
		"\u0001\u0000\u0000\u0000\u00da\u00db\u0005\u0003\u0000\u0000\u00db\u00dd"+
		"\u0001\u0000\u0000\u0000\u00dc\u00ca\u0001\u0000\u0000\u0000\u00dc\u00cb"+
		"\u0001\u0000\u0000\u0000\u00dd\u0013\u0001\u0000\u0000\u0000\u00de\u00df"+
		"\u0005\u00db\u0000\u0000\u00df\u00e0\u0005\u0011\u0000\u0000\u00e0\u00e1"+
		"\u0005\u00db\u0000\u0000\u00e1\u0015\u0001\u0000\u0000\u0000\u00e2\u00e3"+
		"\u0007\t\u0000\u0000\u00e3\u0017\u0001\u0000\u0000\u0000\u00e4\u00e5\u0006"+
		"\f\uffff\uffff\u0000\u00e5\u00ea\u0005\u00dd\u0000\u0000\u00e6\u00ea\u0005"+
		"\u00a4\u0000\u0000\u00e7\u00ea\u0005\u008c\u0000\u0000\u00e8\u00ea\u0005"+
		"\u00a9\u0000\u0000\u00e9\u00e4\u0001\u0000\u0000\u0000\u00e9\u00e6\u0001"+
		"\u0000\u0000\u0000\u00e9\u00e7\u0001\u0000\u0000\u0000\u00e9\u00e8\u0001"+
		"\u0000\u0000\u0000\u00ea\u00f0\u0001\u0000\u0000\u0000\u00eb\u00ec\n\u0005"+
		"\u0000\u0000\u00ec\u00ed\u0005\u00de\u0000\u0000\u00ed\u00ef\u0003\u0018"+
		"\f\u0006\u00ee\u00eb\u0001\u0000\u0000\u0000\u00ef\u00f2\u0001\u0000\u0000"+
		"\u0000\u00f0\u00ee\u0001\u0000\u0000\u0000\u00f0\u00f1\u0001\u0000\u0000"+
		"\u0000\u00f1\u0019\u0001\u0000\u0000\u0000\u00f2\u00f0\u0001\u0000\u0000"+
		"\u0000\u0019\u001d%*BOr\u0082\u0084\u008a\u008f\u0093\u009a\u009f\u00a9"+
		"\u00b0\u00b8\u00c0\u00c6\u00c8\u00ce\u00d3\u00d7\u00dc\u00e9\u00f0";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}