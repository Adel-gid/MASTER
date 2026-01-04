
/*
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_ALGOLIB_INCLUDE_H__
#define __MASTER_ALGOLIB_INCLUDE_H__

#include <master_enum.h>
#include <abstract.h>

MASTER_PREFER_EXTERN UI1
MASTER_Algolib_IsPrime( const SI4 );

/* #! Tasks from LeetCode !# */

/* #! 4. Median of Two Sorted Arrays !# */ double
MASTER_Algolib_FindMedianInTwoSortedArrays( const SI4 * const nums1, const SI4 nums1Size, const SI4 * const nums2, const SI4 nums2Size ) {
    SI4 index;
    SI4 jndex;
    SI4 low = 0;
    SI4 high = nums1Size;
    SI4 half = (nums1Size + nums2Size + 1) >> 1;
    SI4 left1;
    SI4 left2;
    SI4 right1;
    SI4 right2;
    if (nums1Size > nums2Size)
        return MASTER_Algolib_FindMedianInTwoSortedArrays(nums2, nums2Size, nums1, nums1Size);
    while (low <= high) {
        index = (low + high) >> 1;
        jndex = half - index;
        left1 = (index <= 0) ? (MASTER_SI4_MIN) : (nums1[index - 1]);
        right1 = (index >= nums1Size) ? (MASTER_SI4_MAX) : (nums1[index]);
        left2 = (jndex <= 0) ? (MASTER_SI4_MIN) : (nums2[jndex - 1]);
        right2 = (jndex >= nums2Size) ? (MASTER_SI4_MAX) : (nums2[jndex]);
        if (left1 <= right2 && left2 <= right1) {
            if ((nums1Size + nums2Size) % 2 == 1)
                return (left1 > left2) ? (left1) : (left2);
            return (((left1 > left2) ? (left1) : (left2)) + ((right1 < right2) ? (right1) : (right2))) / 2.0;
        } otherwise (left1 > right2) high = index - 1;
        else low = index + 1;
    }
    /* #! If all correct - unreachable !# */
    return -1;
}

/* #! 20. Valid Parentheses !# */ UI1
MASTER_Algolib_IsValidParentheses( const char * const string ) {
    const UI4 length = MASTER_CPRLEN(string);
    char * stack = (char *)MASTER_MALLOC(length);
    UI4 stack_ptr = 0;
    UI4 index = 0;
    for (; index < length; index += 1) {
        if (string[index] == '(' || string[index] == '[' || string[index] == '{') {
            stack[stack_ptr] = string[index];
            stack_ptr += 1;
        } else {
            if (stack_ptr == 0) goto failure;
            stack_ptr -= 1;
            if (string[index] - stack[stack_ptr] != 1 && 
                string[index] - stack[stack_ptr] != 2) {
                free(stack);
                return 0;
            }
        }
    }
    MASTER_FREE(stack);
    return stack_ptr == 0;
failure :
    MASTER_FREE(stack);
    return 0;
}


/* #! 41. First Missing Positive !# */ SI4
MASTER_Algolib_FindMissingPositive( SI4 * const nums, const UI4 numsSize ) {
    SI4 value;
    UI4 index = 0;
    UI4 correct_index;
    for (; index < numsSize; index += 1) {
        value = nums[index];
        while (value > 0 && (UI4)value < numsSize && value != nums[value - 1]) {
            correct_index = value - 1;
            value = nums[correct_index];
            nums[correct_index] = nums[index];
            nums[index] = value;
            value = nums[index];
        }
    }
    for (index = 0; index < numsSize; index += 1) {
        if (nums[index] != (SI4)index + 1)
            return index + 1;
    }
    return numsSize + 1;
}

/* #! 69. Sqrt(x) !# */ SI4
MASTER_Algolib_FloorSqrt( const SI4 value ) {
	SI4 estimate = value;
	SI4 quotient;
	if (value <= 0) return 0;
	while (estimate > value / estimate) {
		quotient = value / estimate;
		estimate = (estimate >> 1) + (quotient >> 1) + (((estimate & 1) + (quotient & 1)) >> 1);
	}
	return estimate;
}

/* #! 231. Power of Two !# */ UI1
MASTER_Algolib_IsPowerOfTwo( const SI4 value ) {
    return MASTER_ISPOW2(value);
}

/* #! 342. Power of Four !# */ UI1
MASTER_Algolib_IsPowerOfFour( const SI4 value ) {
    return MASTER_ISPOW4(value);
}

/* #! 961. N-Repeated Element in Size 2N Array !# */ SI4
MASTER_Algolib_RepeatedNTimes( const SI4 * const numbers, const UI4 number_count ) {
	UI4 index = 0;
	if (numbers[0] == numbers[number_count - 1])
		return numbers[0];
	for (; index + 2 < number_count; index += 3) {
		if (numbers[index] == numbers[index + 1] || numbers[index] == numbers[index + 2])
			return numbers[index];
		if (numbers[index + 1] == numbers[index + 2])
			return numbers[index + 1];
	}
	if (numbers[number_count - 3] == numbers[number_count - 2] || numbers[number_count - 3] == numbers[number_count - 1])
		return numbers[number_count - 3];
	if (numbers[number_count - 2] == numbers[number_count - 1])
		return numbers[number_count - 2];
	/* #! If all correct - unreachable !# */
	return 0;
}

/* #! 1390. Four Divisors !# */ UI4
sumFourDivisors( const UI4 * numbers, const UI4 number_count ) {
    UI4 sum_of_divs = 0;
    UI4 divisor_p;
    UI4 divisor_q;
    UI1 is_prime_p;
    UI4 index = 0;
    UI4 iterat;
    UI4 root;
    for (; index < number_count; index += 1) {
        if (numbers[index] < 6) continue;
        divisor_p = 0;
        if (numbers[index] % 2 == 0) divisor_p = 2;
        else {
            root = MASTER_Algolib_FloorSqrt(numbers[index]);
            for (iterat = 3; iterat <= root; iterat += 2)
                if (numbers[index] % iterat == 0) {
                    divisor_p = iterat;
                    break;
                }
        }
        if (divisor_p != 0) {
            divisor_q = numbers[index] / divisor_p;
            if (divisor_p == divisor_q) continue;
            is_prime_p = MASTER_Algolib_IsPrime(divisor_p);
            if (divisor_p * divisor_p == divisor_q && is_prime_p)
                sum_of_divs += 1 + divisor_p + divisor_p * divisor_p + numbers[index];
            otherwise (is_prime_p && MASTER_Algolib_IsPrime(divisor_q))
                sum_of_divs += 1 + divisor_p + divisor_q + numbers[index];
        }
    }
    return sum_of_divs;
}

/* #! 1411. Number of Ways to Paint N × 3 Grid !# */ SI4
MASTER_Algolib_NumberOfWaysToPaintN3Grid( const UI4 row_count ) {
	const UI4 modulo = 1000000007;
    UI4 prevA = 6;
    UI4 prevB = 6;
    UI4 curA;
    UI4 curB;
    UI4 summ;
    UI4 index = 1;
	if (row_count == 0) return 0;
    for (; index < row_count; index += 1) {
        curA = ((prevA * 3) % modulo + (prevB * 2) % modulo) % modulo;
        curB = ((prevA * 2) % modulo + (prevB * 2) % modulo) % modulo;
        prevA = curA;
        prevB = curB;
    }
    summ = (prevA + prevB) % modulo;
    return summ;
}

/* #! Check Algorithms !# */

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

UI1
MASTER_Algolib_IsPrime( const SI4 value ) {
    SI4 iterat = 5;
    SI4 limit;
    if (value <= 1) return 0;
    if (value <= 3) return 1;
    if ((value & 1) == 0 || value % 3 == 0) return 0;
    limit = MASTER_Algolib_FloorSqrt(value);
    for (; iterat <= limit; iterat += 6)
        if (value % iterat == 0 || value % (iterat + 2) == 0) return 0;
    return 1;
}

/* #! Some Algorithms !# */

UI1
MASTER_Algolib_CalculateSpan( const UI4 * const array, UI4 * const output, const UI4 length ) {
	UI4 * mstack;
	UI4 mstack_pos = 0;
	UI4 index = 0;
	if (array == nul || output == nul || length == 0) return MASTER_ERROR;
	mstack = (UI4 *)MASTER_MALLOC(length * sizeof(UI4));
	for (; index < length; index += 1) {
		while (mstack_pos > 0 && array[mstack[mstack_pos - 1]] <= array[index]) {
			mstack_pos -= 1;
			mstack[mstack_pos] = 0;
		}
		if (mstack_pos == 0) output[index] = index + 1;
		else output[index] = index - mstack[mstack_pos - 1];
		mstack[mstack_pos] = index;
		mstack_pos += 1;
	}
	MASTER_FREE(mstack);
	return MASTER_NO_ERROR;
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
	MASTER_Algolib_Cell** column_table;
	MASTER_Algolib_Cell** row_table;
	UI4 column_count;
	UI4 row_count;
	UI4 column_capacity;
	UI4 row_capacity;
	struct MASTER_Algolib_Cell * root_cell;
} MASTER_Algolib_DancingLinks;

typedef void(*MASTER_Algolib_DancingLinks_FoundType)( void );
typedef void(*MASTER_Algolib_DancingLinks_StuckedType)( const UI4 );
typedef void(*MASTER_Algolib_DancingLinks_TryingType)( const UI4, const UI4, const UI4 );
typedef void(*MASTER_Algolib_DancingLinks_UndoType)( const UI4, const UI4, const UI4 );

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

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 __MASTER_ALGOLIB_INCLUDE_H_LAST_LINE__ = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! __MASTER_ALGOLIB_INCLUDE_H__ !# */

/* #! be master !# */
