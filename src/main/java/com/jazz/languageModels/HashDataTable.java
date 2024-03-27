package com.jazz.languageModels;

import tech.tablesaw.api.Table;

import java.util.Map;
public class HashDataTable {

    // Function to access and print the value for a given key
    private static void accessTable(Map<String, Table> map, String key) {
        Table table = map.get(key);
        if (table != null) {
            System.out.println("Table for key '" + key + "':\n" + table);
        } else {
            System.out.println("Key '" + key + "' not found in the HashMap.");
        }
    }

    // Function to modify the value for a given key
    private static void modifyTable(Map<String, Table> map, String key, String columnName, int newValue) {
        Table table = map.get(key);
        if (table != null) {
            table.intColumn(columnName).set(0, newValue);
            System.out.println("Modified Table for key '" + key + "':\n" + table);
        } else {
            System.out.println("Key '" + key + "' not found in the HashMap. Modification failed.");
        }
    }

    // Function to remove a key from the HashMap
    private static void removeKey(Map<String, Table> map, String key) {
        if (map.containsKey(key)) {
            map.remove(key);
            System.out.println("Key '" + key + "' removed from the HashMap.");
        } else {
            System.out.println("Key '" + key + "' not found in the HashMap. Removal failed.");
        }
    }

    // Function to check if a key exists in the HashMap
    private static boolean keyExists(Map<String, Table> map, String key) {
        return map.containsKey(key);
    }
}
