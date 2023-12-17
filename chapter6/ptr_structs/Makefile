CC=cc

all:
	$(CC) -o main main.c -ggdb
test_bin_search:
	$(CC) -o bin_search_test bin_search.test.c -ggdb && ./bin_search_test
test_extract_word:
	$(CC) -o extract_word_test extract_word.test.c -ggdb && ./extract_word_test
clear:
	rm -rf main core*
