/**
 * Copyright © 2013, 2014 Red Hat, Casey Dahlin <cdahlin@redhat.com>
 *
 * This file is part of libason.
 *
 * libason is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libason is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libason. If not, see <http://www.gnu.org/licenses/>.
 **/

#include <stdio.h>
#include <stdlib.h>

#include <ason/value.h>
#include <ason/output.h>
#include <ason/read.h>
#include <ason/iter.h>

#include "harness.h"

TESTS("Object Iteration",
      "Universal Object Iteration",
      "List Iteration");

/**
 * Basic exercise of the parser.
 **/
TEST_MAIN("Iteration")
{
	TEST_INIT();
	ason_t *a;
	char *str;
	ason_iter_t *iter;
	int i;

	a = ason_read("{ \"foo\": 6, \"bar\": 7, \"baz\": 8 }", NULL);
	iter = ason_iterate(a);

	TEST("Object Iteration") {
		struct {
			char name[3];
			int value;
			int seen;
		} items[3] = {
			{ "foo", 6, 0},
			{ "bar", 7, 0},
			{ "baz", 8, 0},
		};


		REQUIRE(ason_iter_type(iter) == ASON_TYPE_OBJECT);
		REQUIRE(ason_iter_enter(iter));

		do {
			for (i = 0; i < 3; i++) {
				str = ason_iter_key(iter);

				if (! strcmp(items[i].name, str)) {
					REQUIRE(items[i].value == ason_iter_long(iter));
					REQUIRE(! items[i].seen);
					items[i].seen = 1;
					free(str);
					break;
				}

				free(str);
			}

			REQUIRE(i < 3);
		} while(ason_iter_next(iter));

		for (i = 0; i < 3; i++)
			REQUIRE(items[i].seen);
	}

	ason_destroy(a);
	ason_iter_destroy(iter);

	a = ason_read("{ \"foo\": 6, \"bar\": 7, \"baz\": 8, * }", NULL);
	iter = ason_iterate(a);

	TEST("Universal Object Iteration") {
		struct {
			char name[3];
			int value;
			int seen;
		} items[3] = {
			{ "foo", 6, 0},
			{ "bar", 7, 0},
			{ "baz", 8, 0},
		};


		REQUIRE(ason_iter_type(iter) == ASON_TYPE_UOBJECT);
		REQUIRE(ason_iter_enter(iter));

		do {
			for (i = 0; i < 3; i++) {
				str = ason_iter_key(iter);

				if (! strcmp(items[i].name, str)) {
					REQUIRE(items[i].value == ason_iter_long(iter));
					REQUIRE(! items[i].seen);
					items[i].seen = 1;
					free(str);
					break;
				}

				free(str);
			}

			REQUIRE(i < 3);
		} while(ason_iter_next(iter));

		for (i = 0; i < 3; i++)
			REQUIRE(items[i].seen);
	}

	ason_destroy(a);
	ason_iter_destroy(iter);

	a = ason_read("[ \"foo\", \"bar\", \"baz\" ]", NULL);
	iter = ason_iterate(a);

	TEST("List Iteration") {
		char *values[3] = { "foo", "bar", "baz" };

		REQUIRE(ason_iter_type(iter) == ASON_TYPE_LIST);
		REQUIRE(ason_iter_enter(iter));

		i = 0;
		do {
			REQUIRE(i < 3);

			str = ason_iter_string(iter);

			REQUIRE(! strcmp(values[i], str));
			free(str);

			i++;
		} while(ason_iter_next(iter));
	}

	ason_destroy(a);
	ason_iter_destroy(iter);

	return 0;
}

