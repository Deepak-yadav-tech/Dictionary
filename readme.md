# Backend Dictionary System

## 1. Project Overview

This project implements a backend-only dictionary system that stores words, supports exact word search, and provides prefix-based autocomplete suggestions.

The implementation is written in **C++** and runs in the terminal/command line. It uses in-memory storage, so no database setup or external libraries are required.

### Features

- **Add a word:** Adds a word to the dictionary if it does not already exist.
- **Exact word search:** Checks whether a word exists. Each successful search increases that word's search frequency.
- **Prefix-based suggestions:** Finds words beginning with a given prefix.
- **Ranking:** Sorts matching words by search frequency (highest first). When frequencies are equal, words are sorted alphabetically.
- **Top-K results:** Returns no more than the requested number of suggestions.
- **Input validation:** Rejects non-positive values of K.
- **Interactive menu:** Provides options to add, search, suggest, and exit.

## 2. Technology and Requirements

- Language: C++
- Standard library components:
  - `unordered_map` for word-to-frequency storage
  - `vector` for collecting matching words
  - `sort` for ordering suggestions
  - `string` for word and prefix handling
  - `iostream` for terminal input and output
- Compiler: A C++ compiler supporting C++11 or later (for example, `g++`).
- External libraries/frameworks: None.
- Database: Not required; data is stored in memory.

## 3. Data Structures

### Word-frequency map

The program uses:

```cpp
unordered_map<string, int> dic;
```

- **Key (`string`):** The word stored in the dictionary.
- **Value (`int`):** The word's search frequency.
- A newly added word starts with frequency `1`.
- Every successful exact search increments its frequency by `1`.
- Adding a duplicate word does not reset or increment its frequency.

An `unordered_map` provides average O(1) lookup and update time.

### Suggestion result vector

The program uses:

```cpp
vector<string> res;
```

This vector temporarily stores words that match the entered prefix. It is sorted before the top-K results are displayed.

## 4. Logic and Approach

### Add a word

1. Read the word.
2. Check whether it already exists in the map.
3. If it exists, display `Already exists`.
4. Otherwise, store the word with an initial frequency of `1`.

### Search for a word

1. Read the word.
2. Check whether it exists in the map.
3. If found, increase its frequency by `1` and display `Found`.
4. Otherwise, display `Not found`.

### Generate prefix suggestions

1. Read a prefix and the requested number of suggestions, `K`.
2. Reject the request if `K <= 0`.
3. Iterate through the stored words.
4. Select words whose prefix starts at index `0`.
5. Sort matching words:
   - First by frequency in descending order.
   - Then alphabetically in ascending order when frequencies are equal.
6. Display at most `K` words.
7. If no words match, display `No suggestions found` (if this message is implemented in the source code).

### Ranking example

Suppose the dictionary contains the following entries:

| Word | Search frequency |
|---|---:|
| `apple` | 2 |
| `application` | 4 |
| `apply` | 4 |
| `appetizer` | 1 |
| `banana` | 3 |

For prefix `app` and `K = 3`, the suggestions are:

```text
[application, apply, apple]
```

`banana` is excluded because it does not start with `app`. `appetizer` is excluded from the top three because its frequency is lower.



## 5. How to Compile and Run

### Using g++

1. Save the source code as `main.cpp`.
2. Open a terminal in the directory containing the file.
3. Compile:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o dictionary
```

4. Run on Linux/macOS:

```bash
./dictionary
```

On Windows using MinGW:

```bash
dictionary.exe
```

If your IDE provides a C++ compiler, you can also build and run the source file directly.

## 6. How to Test

Start the program and use the menu:

```text
1. Add Word
2. Search Word
3. Suggest Words
4. Exit
```

Suggested manual test cases:

| Test | Actions | Expected behavior |
|---|---|---|
| Add new word | Add `apple` | Word is added with frequency 1 |
| Add duplicate | Add `apple` again | Duplicate message; frequency remains unchanged |
| Search existing word | Search `apple` | Displays `Found`; frequency increases by 1 |
| Search missing word | Search `orange` | Displays `Not found` |
| Prefix match | Add `apple`, `apply`; request prefix `app` | Both words are eligible for suggestions |
| No prefix match | Request prefix `xyz` | Empty result  |
| Top-K limit | Have at least three matches; request K = 2 | At most two suggestions are displayed |
| Ranking | Search one matching word more often than another | Higher-frequency word appears first |
| Alphabetical tie-break | Give two matching words the same frequency | Alphabetically earlier word appears first |
| Invalid K | Enter K = 0 or a negative number | Displays validation message and returns to menu |



## 7. Summary

This project demonstrates an in-memory dictionary using C++ standard-library data structures. It supports exact word lookup, frequency tracking, prefix-based suggestions, deterministic ranking, and top-K output without external libraries or frameworks.
