/**
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

#ifndef ASON_PARSE_H
#define ASON_PARSE_H

#include <ason/value.h>

#ifdef __cplusplus
extern "C" {
#endif

ason_t *ason_read(const char *text);
ason_t *ason_readn(const char *text, size_t length);

#ifdef __cplusplus
}
#endif

#endif /* ASON_PARSE_H */
