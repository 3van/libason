TESTS = parser_test	  \
	esc_parser_test	  \
	print_object	  \
	complement_test	  \
	intersection_test \
	iterator_test
noinst_PROGRAMS = $(TESTS)

MOSTLYCLEANFILES=*.gcda *.gcno *.gcov

parser_test_SOURCES = parser_test.c harness.c
parser_test_LDADD = ../src/libason.la

esc_parser_test_SOURCES = esc_parser_test.c harness.c
esc_parser_test_LDADD = ../src/libason.la

print_object_SOURCES = print_object.c harness.c
print_object_LDADD = ../src/libason.la

complement_test_SOURCES = complement_test.c harness.c
complement_test_LDADD = ../src/libason.la

intersection_test_SOURCES = intersection_test.c harness.c
intersection_test_LDADD = ../src/libason.la

iterator_test_SOURCES = iterator_test.c harness.c
iterator_test_LDADD = ../src/libason.la
