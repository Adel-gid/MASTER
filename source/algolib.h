
/*
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_ALGOLIB_INCLUDE_H__
#define __MASTER_ALGOLIB_INCLUDE_H__

#include <master_enum.h>

UI1
MASTER_Algolib_CheckBrackets( const char * const string ) {
	UI4 index = 0;
	char bracket;
	MASTER_ByteStack bstack;
	MASTER_ByteStack_Init(&bstack, 32);
	for (; string[index] != 0; index += 1) {
		if (MASTER_ASCII_IS_OPEN_BRACKET(string[index])) {
			if (MASTER_ByteStack_AddByte(&bstack, string[index]) == MASTER_ERROR) goto failure;
		} otherwise (MASTER_ASCII_IS_CLOSE_BRACKET(string[index])) {
			bracket = MASTER_ByteStack_PeekByte(&bstack, 0);
			if ((bracket == '(' && string[index] != ')') ||
				(bracket == '[' && string[index] != ']') ||
				(bracket == '{' && string[index] != '}') ||
				bracket == 0)
				goto failure;
			MASTER_ByteStack_PopByte(&bstack);
		}
	}
	if (MASTER_ByteStack_IsEmpty(&bstack) == 0)
		goto failure;
	MASTER_ByteStack_Free(&bstack);
	return 1;
failure :
	MASTER_ByteStack_Free(&bstack);
	return 0;
}

/* #! Dancing Links !# */

typedef struct MASTER_Algolib_Cell MASTER_Algolib_Cell;

struct MASTER_Algolib_Cell {
	MASTER_Algolib_Cell * up_cell;
	MASTER_Algolib_Cell * left_cell;
	MASTER_Algolib_Cell * down_cell;
	MASTER_Algolib_Cell * right_cell;
	UI4 row_col_id;
	union {
		MASTER_Algolib_Cell * header_cell; /* #! Row & other !# */
		UI4 ones_count; /* #! Column !# */
	} extra;
};

typedef struct {
	struct MASTER_Algolib_Cell** column_table;
	struct MASTER_Algolib_Cell** row_table;
	UI4 column_count;
	UI4 row_count;
	UI4 column_capacity;
	UI4 row_capacity;
	struct MASTER_Algolib_Cell * root_cell;
} MASTER_Algolib_DancingLinks;

#define MASTER_ALGOLIB_CELL_DELETE_VERTI( cur_cell ) do { \
		(cur_cell)->up_cell->down_cell = (cur_cell)->down_cell; \
		(cur_cell)->down_cell->up_cell = (cur_cell)->up_cell; \
	} while (0)

#define MASTER_ALGOLIB_CELL_DELETE_HORIZ( cur_cell ) do { \
		(cur_cell)->left_cell->right_cell = (cur_cell)->right_cell; \
		(cur_cell)->right_cell->left_cell = (cur_cell)->left_cell; \
	} while (0)

#define MASTER_ALGOLIB_CELL_DELETE( cur_cell ) do { \
		MASTER_ALGOLIB_CELL_DELETE_VERTI(cur_cell); \
		MASTER_ALGOLIB_CELL_DELETE_HORIZ(cur_cell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_REINSTATE_VERTI( cur_cell ) do { \
		(cur_cell)->up_cell->down_cell = (cur_cell)->down_cell->up_cell = (cur_cell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_REINSTATE_HORIZ( cur_cell ) do { \
		(cur_cell)->left_cell->right_cell = (cur_cell)->right_cell->left_cell = (cur_cell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_REINSTATE( cur_cell ) do { \
		MASTER_ALGOLIB_CELL_REINSTATE_VERTI(cur_cell); \
		MASTER_ALGOLIB_CELL_REINSTATE_HORIZ(cur_cell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_LINK_SELF_VERTI( cur_cell) do { \
		(cur_cell)->up_cell = (cur_cell)->down_cell = (cur_cell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_LINK_SELF_HORIZ( cur_cell) do { \
		(cur_cell)->left_cell = (cur_cell)->right_cell = (cur_cell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_LINK_SELF( cur_cell ) do { \
		MASTER_ALGOLIB_CELL_LINK_SELF_VERTI(cur_cell); \
		MASTER_ALGOLIB_CELL_LINK_SELF_HORIZ(cur_cell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_INSERT_LEFT( cur_cell, new_cell ) do { \
		(new_cell)->left_cell = (cur_cell)->left_cell; \
		(new_cell)->right_cell = (cur_cell); \
		(cur_cell)->left_cell = (cur_cell)->left_cell->right_cell = (new_cell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_INSERT_UP( cur_cell, new_cell ) do { \
		(new_cell)->up_cell = (cur_cell)->up_cell; \
		(new_cell)->down_cell = (cur_cell); \
		(cur_cell)->up_cell = (cur_cell)->up_cell->down_cell = (new_cell); \
	} while (0)

MASTER_Algolib_Cell *
MASTER_Algolib_Cell_Create( void ) {
	MASTER_Algolib_Cell * cur_cell = (MASTER_Algolib_Cell *)MASTER_MALLOC(sizeof(MASTER_Algolib_Cell));
	MASTER_ALGOLIB_CELL_LINK_SELF(cur_cell);
	return cur_cell;
}

void
MASTER_Algolib_DancingLinks_Init( MASTER_Algolib_DancingLinks * const dancing_links ) {
	if (dancing_links == nul) return;
	dancing_links->column_count = 0;
	dancing_links->row_count = 0;
	dancing_links->column_capacity = 8;
	dancing_links->row_capacity = 8;
	dancing_links->column_table = (MASTER_Algolib_Cell**)MASTER_MALLOC(sizeof(MASTER_Algolib_Cell *) * dancing_links->column_capacity);
	dancing_links->row_table = (MASTER_Algolib_Cell**)MASTER_MALLOC(sizeof(MASTER_Algolib_Cell *) * dancing_links->row_capacity);
	dancing_links->root_cell = MASTER_Algolib_Cell_Create();
}

MASTER_Algolib_DancingLinks
MASTER_Algolib_DancingLinks_Create( void ) {
	MASTER_Algolib_DancingLinks dancing_links;
	MASTER_Algolib_DancingLinks_Init(&dancing_links);
	return dancing_links;
}

void
MASTER_Algolib_DancingLinks_AddRow( MASTER_Algolib_DancingLinks * const dancing_links ) {
	if (dancing_links == nul) return;
	if (dancing_links->row_count >= dancing_links->row_capacity) {
		dancing_links->row_capacity <<= 1;
		dancing_links->row_table = (MASTER_Algolib_Cell**)MASTER_REALLOC(dancing_links->row_table, sizeof(MASTER_Algolib_Cell *) * dancing_links->row_capacity);
	}
	dancing_links->row_table[dancing_links->row_count] = nul;
	dancing_links->row_count += 1;
}

void
MASTER_Algolib_DancingLinks_AddColumn( MASTER_Algolib_DancingLinks * const dancing_links ) {
	MASTER_Algolib_Cell * column_cell;
	if (dancing_links == nul) return;
	column_cell = MASTER_Algolib_Cell_Create();
	MASTER_ALGOLIB_CELL_LINK_SELF(column_cell);
	column_cell->row_col_id = dancing_links->column_count;
	column_cell->extra.ones_count = 0;
	MASTER_ALGOLIB_CELL_INSERT_LEFT(dancing_links->root_cell, column_cell);
	if (dancing_links->column_count >= dancing_links->column_capacity) {
		dancing_links->column_capacity <<= 1;
		dancing_links->column_table = (MASTER_Algolib_Cell**)MASTER_REALLOC(dancing_links->column_table, sizeof(MASTER_Algolib_Cell *) * dancing_links->column_capacity);
	}
	dancing_links->column_table[dancing_links->column_count] = column_cell;
	dancing_links->column_count += 1;
}

void
MASTER_Algolib_Cell_FreeRow( MASTER_Algolib_Cell * const cur_cell ) {
	MASTER_Algolib_Cell * next_cell;
	MASTER_Algolib_Cell * iterat;
	if (cur_cell == nul) return;
	iterat = cur_cell->right_cell;
	while (iterat != cur_cell) {
		next_cell = iterat->right_cell;
		MASTER_FREE(iterat);
		iterat = next_cell;
	}
	MASTER_FREE(cur_cell);
}

void
MASTER_Algolib_DancingLinks_Free( MASTER_Algolib_DancingLinks * const dancing_links ) {
	UI4 index = 0;
	if (dancing_links == nul) return;
	for (; index < dancing_links->row_count; index += 1)
		MASTER_Algolib_Cell_FreeRow(dancing_links->row_table[index]);
	for (index = 0; index < dancing_links->column_count; index += 1)
		MASTER_FREE(dancing_links->column_table[index]);
	MASTER_FREE(dancing_links->column_table);
	MASTER_FREE(dancing_links->row_table);
	MASTER_FREE(dancing_links->root_cell);
}

void
MASTER_Algolib_DancingLinks_Set( MASTER_Algolib_DancingLinks * const dancing_links, const UI4 row_id, const UI4 column_id ) {
	MASTER_Algolib_Cell * column_cell;
	MASTER_Algolib_Cell * row_cell;
	MASTER_Algolib_Cell * new_cell;
	MASTER_Algolib_Cell * iterat;
	if (dancing_links == nul) return;
	while (dancing_links->column_count <= column_id)
		MASTER_Algolib_DancingLinks_AddColumn(dancing_links);
	while (dancing_links->row_count <= row_id)
		MASTER_Algolib_DancingLinks_AddRow(dancing_links);
	column_cell = dancing_links->column_table[column_id];
	row_cell = dancing_links->row_table[row_id];
	if (row_cell == nul) {
		new_cell = MASTER_Algolib_Cell_Create();
		new_cell->row_col_id = row_id;
		new_cell->extra.header_cell = column_cell;
		column_cell->extra.ones_count += 1;
		dancing_links->row_table[row_id] = new_cell;
	} else {
		iterat = row_cell->right_cell;
		while (iterat != row_cell) {
			if (iterat->extra.header_cell->row_col_id == column_id) return;
			iterat = iterat->right_cell;
		}
		new_cell = MASTER_Algolib_Cell_Create();
		new_cell->row_col_id = row_id;
		new_cell->extra.header_cell = column_cell;
		column_cell->extra.ones_count += 1;
		MASTER_ALGOLIB_CELL_INSERT_LEFT(row_cell, new_cell);
	}
	MASTER_ALGOLIB_CELL_INSERT_UP(column_cell, new_cell);
}

MASTER_Algolib_Cell *
MASTER_Algolib_DancingLinks_PickColumn( MASTER_Algolib_DancingLinks * const dancing_links ) {
	MASTER_Algolib_Cell * column_cell = nul;
	MASTER_Algolib_Cell * iterat;
	UI4 min_ones = MASTER_UI4_MAX;
	if (dancing_links == nul) return nul;
	iterat = dancing_links->root_cell->right_cell;
	while (iterat != dancing_links->root_cell) {
		if (min_ones > iterat->extra.ones_count) {
			min_ones = iterat->extra.ones_count;
			column_cell = iterat;
		}
		iterat = iterat->right_cell;
	}
	return column_cell;
}

void
MASTER_Algolib_DancingLinks_Cover( MASTER_Algolib_Cell * const column_cell ) {
	MASTER_Algolib_Cell * iterat;
	MASTER_Algolib_Cell * jterat;
	if (column_cell == nul) return;
	MASTER_ALGOLIB_CELL_DELETE_HORIZ(column_cell);
	iterat = column_cell->down_cell;
	while (iterat != column_cell) {
		jterat = iterat->right_cell;
		while (jterat != iterat) {
			MASTER_ALGOLIB_CELL_DELETE_VERTI(jterat);
			jterat->extra.header_cell->extra.ones_count -= 1;
			jterat = jterat->right_cell;
		}
		iterat = iterat->down_cell;
	}
}

void
MASTER_Algolib_DancingLinks_Uncover( MASTER_Algolib_Cell * const column_cell ) {
	MASTER_Algolib_Cell * iterat;
	MASTER_Algolib_Cell * jterat;
	if (column_cell == nul) return;
	iterat = column_cell->up_cell;
	while (iterat != column_cell) {
		jterat = iterat->left_cell;
		while (jterat != iterat) {
			MASTER_ALGOLIB_CELL_REINSTATE_VERTI(jterat);
			jterat->extra.header_cell->extra.ones_count += 1;
			jterat = jterat->left_cell;
		}
		iterat = iterat->up_cell;
	}
	MASTER_ALGOLIB_CELL_REINSTATE_HORIZ(column_cell);
}

typedef void(*MASTER_Algolib_DancingLinks_FoundType)( void );
typedef void(*MASTER_Algolib_DancingLinks_StuckedType)( const UI4 );
typedef void(*MASTER_Algolib_DancingLinks_TryingType)( const UI4, const UI4, const UI4 );
typedef void(*MASTER_Algolib_DancingLinks_UndoType)( const UI4, const UI4, const UI4 );

void
MASTER_Algolib_DancingLinks_Solve( MASTER_Algolib_DancingLinks * const dancing_links, const MASTER_Algolib_DancingLinks_FoundType found_func, const MASTER_Algolib_DancingLinks_StuckedType stucked_func, const MASTER_Algolib_DancingLinks_TryingType trying_func, const MASTER_Algolib_DancingLinks_UndoType undo_func ) {
	MASTER_Algolib_Cell * column_cell;
	MASTER_Algolib_Cell * row_cell;
	MASTER_Algolib_Cell * iterat;
	if (dancing_links == nul) return;
	if (dancing_links->root_cell->right_cell == dancing_links->root_cell) {
		if (found_func != nul)
			found_func();
		return;
	}
	column_cell = MASTER_Algolib_DancingLinks_PickColumn(dancing_links);
	if (column_cell == nul || column_cell->extra.ones_count == 0) {
		if (stucked_func != nul)
			stucked_func(column_cell->row_col_id);
		return;
	}
	MASTER_Algolib_DancingLinks_Cover(column_cell);
	row_cell = column_cell->down_cell;
	while (row_cell != column_cell) {
		if (trying_func != nul)
			trying_func(column_cell->row_col_id, column_cell->extra.ones_count, row_cell->row_col_id);
		iterat = row_cell->right_cell;
		while (iterat != row_cell) {
			MASTER_Algolib_DancingLinks_Cover(iterat->extra.header_cell);
			iterat = iterat->right_cell;
		}
		MASTER_Algolib_DancingLinks_Solve(dancing_links, found_func, stucked_func, trying_func, undo_func);
		if (undo_func != nul)
			undo_func(column_cell->row_col_id, column_cell->extra.ones_count, row_cell->row_col_id);
		iterat = row_cell->right_cell;
		while (iterat != row_cell) {
			MASTER_Algolib_DancingLinks_Uncover(iterat->extra.header_cell);
			iterat = iterat->right_cell;
		}
		row_cell = row_cell->down_cell;
	}
	MASTER_Algolib_DancingLinks_Uncover(column_cell);
}

UI1
MASTER_Algolib_DancingLinks_MakeOptional( MASTER_Algolib_DancingLinks * const dancing_links, const UI4 column_id ) {
	if (dancing_links == nul || column_id >= dancing_links->column_count)
		return MASTER_ERROR;
	/* #! Prevent undeletion by self linking !# */
	MASTER_ALGOLIB_CELL_DELETE_HORIZ(dancing_links->column_table[column_id]);
	MASTER_ALGOLIB_CELL_LINK_SELF_HORIZ(dancing_links->column_table[column_id]);
	return MASTER_NO_ERROR;
}

UI1
MASTER_Algolib_DancingLinks_PickRow( MASTER_Algolib_DancingLinks * const dancing_links, const UI4 row_id ) {
	MASTER_Algolib_Cell * iterat;
	if (dancing_links == nul || row_id >= dancing_links->row_count)
		return MASTER_ERROR;
	if (dancing_links->row_table[row_id] == nul)
		return MASTER_ERROR;
	MASTER_Algolib_DancingLinks_Cover(dancing_links->row_table[row_id]->extra.header_cell);
	iterat = dancing_links->row_table[row_id]->right_cell;
	while (iterat != dancing_links->row_table[row_id]) {
		MASTER_Algolib_DancingLinks_Cover(iterat->extra.header_cell);
		iterat = iterat->right_cell;
	}
	return MASTER_NO_ERROR;
}

UI1
MASTER_Algolib_DancingLinks_RemoveRow( MASTER_Algolib_DancingLinks * const dancing_links, const UI4 row_id ) {
	MASTER_Algolib_Cell * iterat;
	if (dancing_links == nul || row_id >= dancing_links->row_count)
		return MASTER_ERROR;
	if (dancing_links->row_table[row_id] == nul)
		return MASTER_ERROR;
	MASTER_ALGOLIB_CELL_DELETE_VERTI(dancing_links->row_table[row_id]);
	dancing_links->row_table[row_id]->extra.header_cell->extra.ones_count -= 1;
	iterat = dancing_links->row_table[row_id]->right_cell;
	while (iterat != dancing_links->row_table[row_id]) {
		MASTER_ALGOLIB_CELL_DELETE_VERTI(iterat);
		iterat->extra.header_cell->extra.ones_count -= 1;
		iterat = iterat->right_cell;
	}
	return MASTER_NO_ERROR;
}

#endif /* #! __MASTER_ALGOLIB_INCLUDE_H__ !# */

/* #! be master !# */
