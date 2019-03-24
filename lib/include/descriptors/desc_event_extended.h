/*
 * Copyright (c) 2011-2012 - Mauro Carvalho Chehab <mchehab@kernel.org>
 * Copyright (c) 2012 - Andre Roth <neolynx@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 * Or, point your browser to http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 *
 */

#ifndef _DESC_EVENT_EXTENDED_H
#define _DESC_EVENT_EXTENDED_H

#include <stdint.h>
#include <unistd.h> /* ssize_t */

struct dvb_desc_event_extended {
	uint8_t type;
	uint8_t length;
	struct dvb_desc *next;

	union {
		struct {
			uint8_t last_id:4;
			uint8_t id:4;
		};
		uint8_t ids;
	};

	unsigned char language[4];
	char *text;
	char *text_emph;
} __attribute__((packed));

struct dvb_v5_fe_parms;

#ifdef __cplusplus
extern "C" {
#endif

void dvb_desc_event_extended_init (struct dvb_v5_fe_parms *parms, const uint8_t *buf, struct dvb_desc *desc);
void dvb_desc_event_extended_print(struct dvb_v5_fe_parms *parms, const struct dvb_desc *desc);
void dvb_desc_event_extended_free (struct dvb_desc *desc);

#ifdef __cplusplus
}
#endif

#endif
