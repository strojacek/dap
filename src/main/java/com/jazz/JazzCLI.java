package com.jazz;

import com.jazz.interpreter.JazzInterpreter;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;


public class JazzCLI {
        /**
         * Main entry point of the interpreter
         * @param args The arguments that were provided by the user
         */
        public static void main(String[] args) {

            if (args.length != 1) {
                System.out.println("Usage: Jazz <script>");
                System.exit(64);
            }
            if ("--version".equals(args[0]) || "-v".equals(args[0])) {
                showVersion();
                return;
            }
            else if ("--help".equals(args[0]) || "-h".equals(args[0])) {
                showHelp();
                return;
            }
            runScript(args[0]);
        }

        /**
         * Runs a Jazz script
         * @param path The path where the script is stored
         */
        private static void runScript(String path) {
            InputStream inputStream = null;
            JazzInterpreter interpreter = null;
            try {
                // Open file under specified path
                inputStream = new FileInputStream(path);
                // Creates a new JazzInterpreter object instance using the standard input, output and error output stream
                interpreter = new JazzInterpreter(System.in, System.out, System.err);
                // Interprets file content
                interpreter.run(inputStream);
                interpreter.clear();

            }
            catch (IOException exception) {
                System.out.println("Error running script: " + exception.getMessage());
                System.exit(74);
            }
            finally {
                if (inputStream != null) {
                    try {
                        inputStream.close();
                    }
                    catch (IOException exception) {
                        exception.printStackTrace();
                    }
                }
                if (interpreter != null) {
                    interpreter.clear();
                }
            }
        }

        /**
         * Displays the project version in the console
         */
        private static void showVersion() {
            System.out.println(JazzCLI.class.getPackage().getImplementationTitle() +
                    " Version: " + JazzCLI.class.getPackage().getImplementationVersion());
        }

        /**
         * Displays the help of the interpreter CLI in the console
         */
        private static void showHelp() {
            System.out.println(JazzCLI.class.getPackage().getImplementationTitle() +
                    " Help:\n" +
                    "Usage: Jazz (-h|--help|-v|--version|<script>)\n\n" +
                    "Options\n" +
                    "-h, --help\t\tDisplay this help and exit\n" +
                    "-v, --version\t\tShows the version of the installed interpreter and exit\n");
        }
    }