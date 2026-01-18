
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zRIVATE_ALGOLIB_INCLUDE_H
#define MASTER_zRIVATE_ALGOLIB_INCLUDE_H

#include <master_enum.h>
#include <abstract.h>
#include <bitlib.h>

MASTER_BEGIN_DECLARATIONS

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_CheckBrackets, ( const char * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_IsPrime, ( const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, OSI, MASTER_Algolib_RoundSqrt, ( const OSI ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_CalculateSpan, ( const UI4 * const, UI4 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_maxint, MASTER_Algolib_DJB2, ( const UI1 *, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_maxint, MASTER_Algolib_SDBM, ( const UI1 *, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_MurmurHash1, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_MurmurHash1_Aligned, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4 ) );
#if MASTER_64_AVAILABLE
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_Algolib_MurmurHash64A, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_Algolib_MurmurHash64B, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI8 ) );
#endif /* #! 64 Bits !# */
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_MurmurHash2, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_MurmurHash2A, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_MurmurHash2_Aligned,( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_MurmurHash3x32o4, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4, void * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_MurmurHash3x32o16, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4, void * const MASTER_PREFER_RESTRICT ) );
#if MASTER_64_AVAILABLE == 1
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_MurmurHash3x64o16, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4, void * const MASTER_PREFER_RESTRICT ) );
#endif /* #! 64 Bits !# */
typedef struct MASTER_Algolib_ListNode MASTER_Algolib_ListNode;
typedef struct MASTER_Algolib_TreeNode MASTER_Algolib_TreeNode;
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Algolib_ListNode *, MASTER_Algolib_AddTwoNodeNumbers, ( MASTER_Algolib_ListNode *, MASTER_Algolib_ListNode * ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, double, MASTER_Algolib_FindMedianInTwoSortedArrays, ( const SI4 * const, const SI4, const SI4 * const, const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_IsPalindrome, ( const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_IsValidParentheses, ( const char * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_FindMissingPositive, ( SI4 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_FloorSqrt, ( const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_LargestRectangleArea, ( const UI4 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_MaximalRectangle, ( const char * const * const, const UI4, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_SingleNumber, ( const SI4 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_IsPowerOfTwo, ( const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, char**, MASTER_Algolib_BinaryTreePaths, ( MASTER_Algolib_TreeNode *, UI4 * ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_IsPowerOfFour, ( const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_IsRectangleCover, ( const SI4 * const * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_ValidateUTF8, ( const SI1 *, UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, char *, MASTER_Algolib_LicenseKeyFormatting, ( const char * const, const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_ScheduleCourse, ( SI4**, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_MinimumDeleteSum, ( const char * const, const char * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_NumberJewelsInStones, ( char *, char * ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Algolib_TreeNode *, MASTER_Algolib_SubtreeWithAllDeepest, ( MASTER_Algolib_TreeNode * ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_RepeatedNTimes, ( const SI4 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_MaxLevelSum, ( MASTER_Algolib_TreeNode * ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_MinimumTimeToVisitAllPoints, ( const SI4**, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_MaximumProduct, ( MASTER_Algolib_TreeNode * ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_SumOfFourDivisors, ( const UI4 *, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_NumberOfWaysToPaintN3Grid, ( const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_MaximumDotProduct, ( const SI4 * const, const UI4, const SI4 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_TotalMoney, ( const SI4 value ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_MinimumXorSum, ( const UI4 *, const UI4 *, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_LargestMagicSquare, ( const SI4**, const SI4, const SI4 * ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_MaximumMatrixSum, ( const SI4 * const * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_signed_maxint, MASTER_Algolib_CountQuadruplets, ( const SI4 *, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4**, MASTER_Algolib_MergeArrays, ( const SI4**, const UI4, const SI4**, const UI4, SI4 *, SI4** ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_KnightMaximumMoves, ( const SI4, const SI4, const SI4** const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_signed_maxint, MASTER_Algolib_LargestSquareArea, ( SI4**, SI4**, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, double, MASTER_Algolib_SeparateSquares, ( const SI4**, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_signed_maxint, MASTER_Algolib_MinimumCost, ( const SI4 * const, const SI4 * const, const UI4, const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4 *, MASTER_Algolib_BestTower, ( const SI4**, const UI4, const SI4 *, const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_MinimumOperations, ( const SI4 *, const SI4 *, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_AlternatingXor, ( const SI4 * const, const UI4, const SI4, const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4 *, MASTER_Algolib_MinimumFlips, ( UI4, SI4**, UI4, char *, char *, SI4 * ) );

struct MASTER_Algolib_ListNode {
	SI4 value;
	MASTER_Algolib_ListNode * next_node;
};

struct MASTER_Algolib_TreeNode {
	SI4 value;
	struct MASTER_Algolib_TreeNode * left;
	struct MASTER_Algolib_TreeNode * right;
};

/* #! Tasks from LeetCode !# */

/* #! 2. Add Two Numbers !# */ MASTER_Algolib_ListNode *
MASTER_Algolib_AddTwoNodeNumbers( MASTER_Algolib_ListNode * l1, MASTER_Algolib_ListNode * l2 ) {
	MASTER_Algolib_ListNode result = { 0, nul };
	MASTER_Algolib_ListNode * iterat = &result;
	MASTER_Algolib_ListNode * new_node;
	SI1 carry = 0;
	SI1 sum_value;
	while (l1 != nul || l2 != nul || carry > 0) {
		sum_value = carry;
		if (l1 != nul) {
			sum_value += l1->value;
			l1 = l1->next_node;
		}
		if (l2 != nul) {
			sum_value += l2->value;
			l2 = l2->next_node;
		}
		new_node = (MASTER_Algolib_ListNode *)MASTER_CALLOC(1, sizeof(MASTER_Algolib_ListNode));
		new_node->value = sum_value % 10;
		iterat = (iterat->next_node = new_node);
		carry = sum_value >= 10;
	}
	return result.next_node;
}

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

/* #! 9. Palindrome Number !# */ UI1
MASTER_Algolib_IsPalindrome( const SI4 value ) {
	SI4 copy_value = value;
	SI4 reversed = 0;
	if (value < 0) return 0;
	while (copy_value > 0) {
		if (reversed > 214748364 || (reversed == 214748364 && copy_value > 7)) return 0;
		reversed = reversed * 10 + (copy_value % 10);
		copy_value /= 10;
	}
	return reversed == value;
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
MASTER_Algolib_FindMissingPositive( SI4 * const numbers, const UI4 numsSize ) {
	SI4 value;
	UI4 index = 0;
	UI4 correct_index;
	for (; index < numsSize; index += 1) {
		value = numbers[index];
		while (value > 0 && (UI4)value < numsSize && value != numbers[value - 1]) {
			correct_index = value - 1;
			value = numbers[correct_index];
			numbers[correct_index] = numbers[index];
			numbers[index] = value;
			value = numbers[index];
		}
	}
	for (index = 0; index < numsSize; index += 1) {
		if (numbers[index] != (SI4)index + 1)
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

/* #! 84. Largest Rectangle in Histogram !# */ UI4
MASTER_Algolib_LargestRectangleArea( const UI4 * const heights, const UI4 heightsSize ) {
	UI4 * mstack;
	UI4 maxArea = 0;
	UI4 curHeight;
	UI4 popHeight;
	UI4 width;
	UI4 mstack_pos = 0;
	UI4 index = 0;
	mstack = (UI4 *)MASTER_MALLOC((heightsSize + 1) * sizeof(UI4));
	for (; index <= heightsSize; index += 1) {
		curHeight = (index >= heightsSize) ? (0) : (heights[index]);
		while (mstack_pos > 0 && heights[mstack[mstack_pos - 1]] > curHeight) {
			mstack_pos -= 1;
			popHeight = heights[mstack[mstack_pos]];
			width = (mstack_pos == 0) ? (index) : (index - mstack[mstack_pos - 1] - 1);
			MASTER_IMAX(maxArea, width * popHeight);
			mstack[mstack_pos] = 0;
		}
		mstack[mstack_pos] = index;
		mstack_pos += 1;
	}
	MASTER_FREE(mstack);
	return maxArea;
}

/* #! 85. Maximal Rectangle !# */ UI4
MASTER_Algolib_MaximalRectangle( const char * const * const matrix, const UI4 matrixSize, const UI4 matrixColSize ) {
	UI4 index = 0;
	UI4 jndex;
	UI4 maxArea = 0;
	UI4 newArea;
	UI4 heights[200];
	for (; index < matrixSize; index += 1) {
		for (jndex = 0; jndex < matrixColSize; jndex += 1)
			heights[jndex] = (matrix[index][jndex] == '1') ? (heights[jndex] + 1) : (0);
		newArea = MASTER_Algolib_LargestRectangleArea(heights, matrixColSize);
		MASTER_IMAX(maxArea, newArea);
	}
	return maxArea;
}

/* #! 136. Single Number !# */ SI4
MASTER_Algolib_SingleNumber( const SI4 * const numbers, const UI4 numsSize ) {
	UI4 index = 0;
	SI4 answer = 0;
	for (; index < numsSize; index += 1)
		answer ^= numbers[index];
	return answer;
}

/* #! 231. Power of Two !# */ UI1
MASTER_Algolib_IsPowerOfTwo( const SI4 value ) {
	return MASTER_ISPOW2(value);
}

#include <stdio.h>

MASTER_PREFER_STATIC void
MASTER_Algolib_BinaryTreePaths_DFS( MASTER_Algolib_TreeNode * root, SI4 * array, UI4 array_pointer, char*** output, UI4 * capacity, UI4 * pointer ) {
	UI4 index = 0;
	char * outpointer;
	array[array_pointer] = root->value;
	if (root->left == nul && root->right == nul) {
		if (*pointer >= *capacity) {
			*capacity <<= 1;
			*output = (char**)MASTER_REALLOC(*output, *capacity * sizeof(char *));
		}
		(*output)[*pointer] = (char *)MASTER_MALLOC(((array_pointer + 1) * 4 + array_pointer * 2 + 1) * sizeof(char));
		outpointer = (*output)[*pointer];
		outpointer += sprintf(outpointer, "%d", array[index]);
		for (index = 1; index <= array_pointer; index += 1)
			outpointer += sprintf(outpointer, "->%d", array[index]);
		*outpointer = '\0';
		*pointer += 1;
	} else {
		if (root->left != nul)
			MASTER_Algolib_BinaryTreePaths_DFS(root->left, array, array_pointer + 1, output, capacity, pointer);
		if (root->right != nul)
			MASTER_Algolib_BinaryTreePaths_DFS(root->right, array, array_pointer + 1, output, capacity, pointer);
	}
}

/* #! 257. Binary Tree Paths !# */ char**
MASTER_Algolib_BinaryTreePaths( MASTER_Algolib_TreeNode * root, UI4 * returnSize ) {
	UI4 capacity = 32;
	UI4 pointer = 0;
	char** output = (char**)MASTER_MALLOC(capacity * sizeof(char *));
	SI4 * array = (SI4 *)malloc(100 * sizeof(SI4));
	MASTER_Algolib_BinaryTreePaths_DFS(root, array, 0, &output, &capacity, &pointer);
	MASTER_FREE(array);
	*returnSize = pointer;
	return output;
}

/* #! 342. Power of Four !# */ UI1
MASTER_Algolib_IsPowerOfFour( const SI4 value ) {
	return MASTER_ISPOW4(value);
}

typedef struct {
	SI4 x;
	SI4 y;
} MASTER_Algolib_IsRectangleCover_Point;

MASTER_PREFER_STATIC SI4
MASTER_Algolib_IsRectangleCover_ComparePoints( const void * data1, const void * data2 ) {
	const MASTER_Algolib_IsRectangleCover_Point * point1 = (const MASTER_Algolib_IsRectangleCover_Point *)data1;
	const MASTER_Algolib_IsRectangleCover_Point * point2 = (const MASTER_Algolib_IsRectangleCover_Point *)data2;
	if (point1->x != point2->x)
		return (point1->x < point2->x) ? (-1) : (+1);
	if (point1->y != point2->y)
		return (point1->y < point2->y) ? (-1) : (+1);
	return 0;
}

/* #! 391. Perfect Rectangle !# */ UI1
MASTER_Algolib_IsRectangleCover( const SI4 * const * const rectangles, const UI4 rectanglesSize ) {
	MASTER_Algolib_IsRectangleCover_Point * container = (MASTER_Algolib_IsRectangleCover_Point *)MASTER_MALLOC(rectanglesSize * 4 * sizeof(MASTER_Algolib_IsRectangleCover_Point));
	MASTER_Algolib_IsRectangleCover_Point corners[4];
	UI1 cornerPtr = 0;
	UI4 containerPtr = 0;
	MASTER_signed_maxint sumArea = 0;
	UI4 index = 0;
	UI4 jndex;
	SI4 rectX1;
	SI4 rectY1;
	SI4 rectX2;
	SI4 rectY2;
	SI4 bigX1 = MASTER_SI4_MAX;
	SI4 bigY1 = MASTER_SI4_MAX;
	SI4 bigX2 = MASTER_SI4_MIN;
	SI4 bigY2 = MASTER_SI4_MIN;
	for (; index < rectanglesSize; index += 1) {
		rectX1 = rectangles[index][0];
		rectY1 = rectangles[index][1];
		rectX2 = rectangles[index][2];
		rectY2 = rectangles[index][3];
		sumArea += (MASTER_signed_maxint)(rectX2 - rectX1) * (MASTER_signed_maxint)(rectY2 - rectY1);
		MASTER_IMIN(bigX1, rectX1);
		MASTER_IMAX(bigX2, rectX2);
		MASTER_IMIN(bigY1, rectY1);
		MASTER_IMAX(bigY2, rectY2);
		container[containerPtr].x = rectX1;
		container[containerPtr].y = rectY1;
		container[(containerPtr += 1)].x = rectX1;
		container[containerPtr].y = rectY2;
		container[(containerPtr += 1)].x = rectX2;
		container[containerPtr].y = rectY1;
		container[(containerPtr += 1)].x = rectX2;
		container[containerPtr].y = rectY2;
		containerPtr += 1;
	}
	if (sumArea != (MASTER_signed_maxint)(bigX2 - bigX1) * (MASTER_signed_maxint)(bigY2 - bigY1)) {
		MASTER_FREE(container);
		return 0;
	}
	qsort(container, containerPtr, sizeof(MASTER_Algolib_IsRectangleCover_Point), MASTER_Algolib_IsRectangleCover_ComparePoints);
	for (index = 0; index < containerPtr;) {
		jndex = index + 1;
		while (jndex < containerPtr && container[index].x == container[jndex].x && container[index].y == container[jndex].y)
			jndex += 1;
		if ((jndex - index) & 1) {
			if (cornerPtr >= 4) {
				MASTER_FREE(container);
				return 0;
			}
			corners[cornerPtr] = container[index];
			cornerPtr += 1;
		}
		index = jndex;
	}
	MASTER_FREE(container);
	if (cornerPtr != 4)
		return 0;
	return corners[0].x == bigX1 && corners[0].y == bigY1 &&
		   corners[1].x == bigX1 && corners[1].y == bigY2 &&
		   corners[2].x == bigX2 && corners[2].y == bigY1 &&
		   corners[3].x == bigX2 && corners[3].y == bigY2;
}

/* #! 393. UTF-8 Validation !# */ UI1
MASTER_Algolib_ValidateUTF8( const SI1 * data, UI4 dataSize ) {
	while (dataSize > 0) {
		if ((data[0] & 0x80) == 0) {
			dataSize -= 1;
			data += 1;
		} otherwise ((data[0] & 0xE0) == 0xC0) {
			if (dataSize < 2) return 0;
			if ((data[1] & 0xC0) != 0x80) return 0;
			dataSize -= 2;
			data += 2;
		} otherwise ((data[0] & 0xF0) == 0xE0) {
			if (dataSize < 3) return 0;
			if ((data[1] & 0xC0) != 0x80) return 0;
			if ((data[2] & 0xC0) != 0x80) return 0;
			dataSize -= 3;
			data += 3;
		} otherwise ((data[0] & 0xF8) == 0xF0) {
			if (dataSize < 4) return 0;
			if ((data[1] & 0xC0) != 0x80) return 0;
			if ((data[2] & 0xC0) != 0x80) return 0;
			if ((data[3] & 0xC0) != 0x80) return 0;
			dataSize -= 4;
			data += 4;
		} else return 0;
	}
	return 1;
}

#include <ctype.h>

/* #! 482. License Key Formatting !# */ char *
MASTER_Algolib_LicenseKeyFormatting( const char * const string, const SI4 key_length ) {
	const UI4 length = MASTER_CPRLEN(string);
	UI4 index = length - 1;
	UI4 jndex = 0;
	UI4 count = 0;
	char * output = (char *)MASTER_CALLOC((length << 1) | 1, sizeof(char));
	for (;; index -= 1) {
		if (string[index] != '-') {
			if (count > 0 && count % key_length == 0) {
				output[jndex] = '-';
				jndex += 1;
				count = 0;
			}
			output[jndex] = toupper(string[index]);
			jndex += 1;
			count += 1;
		}
		if (index == 0) break;
	}
	if (jndex == 0) return output;
	for (index = 0, jndex -= 1; index < jndex; index += 1, jndex -= 1) {
		output[index] ^= output[jndex];
		output[jndex] ^= output[index];
		output[index] ^= output[jndex];
	}
	return output;
}

MASTER_PREFER_STATIC SI4
MASTER_Algolib_ScheduleCourse_Compare( const void * const data1, const void * const data2 ) {
	return (*(const SI4 * const *)data1)[1] - (*(const SI4 * const *)data2)[1];
}

typedef struct {
	UI4 data[10000];
	UI4 capacity;
	UI4 length;
} MASTER_Algolib_ScheduleCourse_MaxHeap;

MASTER_PREFER_STATIC void
MASTER_Algolib_ScheduleCourse_MaxHeap_Push( MASTER_Algolib_ScheduleCourse_MaxHeap * const heap, const SI4 value ) {
	UI4 index = heap->length;
	UI4 parent;
	if (index >= heap->capacity) return;
	heap->data[index] = value;
	heap->length += 1;
	while (index > 0) {
		parent = (index - 1) >> 1;
		if (heap->data[index] > heap->data[parent]) {
			heap->data[index] ^= heap->data[parent];
			heap->data[parent] ^= heap->data[index];
			heap->data[index] ^= heap->data[parent];
			index = parent;
		} else break;
	}
}

MASTER_PREFER_STATIC SI4
MASTER_Algolib_ScheduleCourse_MaxHeap_Pop( MASTER_Algolib_ScheduleCourse_MaxHeap * const heap ) {
	UI4 index = 0;
	UI4 left;
	UI4 right;
	UI4 largest;
	UI4 temp;
	SI4 maxValue = heap->data[0];
	if (heap->length == 0) return -1;
	heap->length -= 1;
	heap->data[0] = heap->data[heap->length];
	while (((index << 1) | 1) < heap->length) {
		left = (index << 1) | 1;
		right = (index + 1) << 1;
		largest = index;
		if (left < heap->length && heap->data[left] > heap->data[largest])
			largest = left;
		if (right < heap->length && heap->data[right] > heap->data[largest])
			largest = right;
		if (largest != index) {
			temp = heap->data[largest];
			heap->data[largest] = heap->data[index];
			heap->data[index] = temp;
			index = largest;
		} else break;
	}
	return maxValue;
}

/* #! 630. Course Schedule III !# */ SI4
MASTER_Algolib_ScheduleCourse( SI4** courses, const UI4 coursesSize ) {
	SI4 time = 0;
	UI4 index = 0;
	UI4 duration;
	UI4 deadline;
	MASTER_Algolib_ScheduleCourse_MaxHeap heap;
	qsort(courses, coursesSize, sizeof(SI4 *), MASTER_Algolib_ScheduleCourse_Compare);
	heap.length = 0;
	heap.capacity = coursesSize;
	for (; index < coursesSize; index += 1) {
		duration = courses[index][0];
		deadline = courses[index][1];
		if (time + duration <= deadline) {
			time += duration;
			MASTER_Algolib_ScheduleCourse_MaxHeap_Push(&heap, duration);
		} otherwise (heap.length > 0 && heap.data[0] > duration) {
			time -= MASTER_Algolib_ScheduleCourse_MaxHeap_Pop(&heap);
			time += duration;
			MASTER_Algolib_ScheduleCourse_MaxHeap_Push(&heap, duration);
		}
	}
	return heap.length;
}

/* #! 712. Minimum ASCII Delete Sum for Two Strings !# */ SI4
MASTER_Algolib_MinimumDeleteSum( const char * const string1, const char * const string2 ) {
	const UI4 length1 = MASTER_CPRLEN(string1);
	const UI4 length2 = MASTER_CPRLEN(string2);
	UI4 index = 0;
	UI4 jndex;
	UI4 total = 0;
	UI4 * prev;
	UI4 * curr;
	UI4 * for_swap;
	if (length1 < length2)
		return MASTER_Algolib_MinimumDeleteSum(string2, string1);
	prev = (UI4 *)MASTER_CALLOC(length2 + 1, sizeof(UI4));
	curr = (UI4 *)MASTER_CALLOC(length2 + 1, sizeof(UI4));
	for (; index < length2; index += 1)
		total += string1[index] + string2[index];
	for (; index < length1; index += 1)
		total += string1[index];
	for (index = 1; index <= length1; index += 1) {
		for (jndex = 1; jndex <= length2; jndex += 1) {
			if (string1[index - 1] == string2[jndex - 1])
				curr[jndex] = prev[jndex - 1] + string1[index - 1];
			else
				curr[jndex] = MASTER_MAX(prev[jndex], curr[jndex - 1]);
		}
		for_swap = prev;
		prev = curr;
		curr = for_swap;
	}
	total -= prev[length2] << 1;
	MASTER_FREE(prev);
	MASTER_FREE(curr);
	return total;
}

/* #! 771. Jewels and Stones !# */ SI4
MASTER_Algolib_NumberJewelsInStones( char * jewels, char * stones ) {
	SI4 count = 0;
	UI1 set[255] = { 0 };
	for (; *jewels != 0; jewels += 1)
		set[(UI1)*jewels] = 1;
	for (; *stones != 0; stones += 1)
		count += set[(UI1)*stones];
	return count;
}

MASTER_PREFER_STATIC void
MASTER_Algolib_SubtreeWithAllDeepest_DFS( MASTER_Algolib_TreeNode * const root, MASTER_Algolib_TreeNode** const outNode, UI4 * const outDepth ) {
	MASTER_Algolib_TreeNode * leftNode;
	MASTER_Algolib_TreeNode * rightNode;
	UI4 leftDepth;
	UI4 rightDepth;
	if (root == nul) {
		*outNode = nul;
		*outDepth = 0;
		return;
	}
	MASTER_Algolib_SubtreeWithAllDeepest_DFS(root->left, &leftNode, &leftDepth);
	MASTER_Algolib_SubtreeWithAllDeepest_DFS(root->right, &rightNode, &rightDepth);
	if (leftDepth > rightDepth) {
		*outNode = leftNode;
		*outDepth = leftDepth + 1;
	} otherwise (rightDepth > leftDepth) {
		*outNode = rightNode;
		*outDepth = rightDepth + 1;
	} else {
		*outNode = root;
		*outDepth = leftDepth + 1;
	}
}

/* #! 865. Smallest Subtree with all the Deepest Nodes !# */ MASTER_Algolib_TreeNode *
MASTER_Algolib_SubtreeWithAllDeepest( MASTER_Algolib_TreeNode * root ) {
	MASTER_Algolib_TreeNode * outNode;
	UI4 depth;
	MASTER_Algolib_SubtreeWithAllDeepest_DFS(root, &outNode, &depth);
	return outNode;
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

/* #! 1123. Lowest Common Ancestor of Deepest Leaves !# */
#define MASTER_Algolib_LCADeepestLeaves( root ) MASTER_Algolib_SubtreeWithAllDeepest(root)

/* #! 1161. Maximum Level Sum of a Binary Tree !# */ SI4
MASTER_Algolib_MaxLevelSum( MASTER_Algolib_TreeNode * root ) {
	MASTER_Algolib_TreeNode * queue[10000];
	MASTER_Algolib_TreeNode * node;
	SI4 level = 1;
	SI4 levelBest = 1;
	SI4 front = 0;
	SI4 rear = 0;
	SI4 maxSum = root->value;
	SI4 curSum;
	SI4 levelSize;
	SI4 index;
	queue[rear] = root;
	rear += 1;
	while (front < rear) {
		levelSize = rear - front;
		curSum = 0;
		for (index = 0; index < levelSize; index += 1) {
			node = queue[front];
			front += 1;
			curSum += node->value;
			if (node->left != nul) {
				queue[rear] = node->left;
				rear += 1;
			}
			if (node->right != nul) {
				queue[rear] = node->right;
				rear += 1;
			}
		}
		if (maxSum < curSum) {
			maxSum = curSum;
			levelBest = level;
		}
		level += 1;
	}
	return levelBest;
}

/* #! 1266. Minimum Time Visiting All Points !# */ UI4
MASTER_Algolib_MinimumTimeToVisitAllPoints( const SI4** points, const UI4 pointsSize ) {
	UI4 index = 1;
	UI4 total_time = 0;
	SI4 deltaX;
	SI4 deltaY;
	for (; index < pointsSize; index += 1) {
		deltaX = MASTER_ABS(points[index - 1][0] - points[index][0]);
		deltaY = MASTER_ABS(points[index - 1][1] - points[index][1]);
		total_time += MASTER_MAX(deltaX, deltaY);
	}
	return total_time;
}

MASTER_PREFER_STATIC SI4
maxProduct_DFS( MASTER_Algolib_TreeNode * root, SI4 * const subTreeSums, UI4 * const index ) {
	SI4 totalSum = root->value;
	if (root->left != nul)
		totalSum += maxProduct_DFS(root->left, subTreeSums, index);
	if (root->right != nul)
		totalSum += maxProduct_DFS(root->right, subTreeSums, index);
	subTreeSums[*index] = totalSum;
	*index += 1;
	return totalSum;
}

/* #! 1339. Maximum Product of Splitted Binary Tree !# */ SI4
MASTER_Algolib_MaximumProduct( MASTER_Algolib_TreeNode * root ) {
	SI4 * subTreeSums = (SI4 *)MASTER_MALLOC(50000 * sizeof(SI4));
	UI4 index = 0;
	UI4 jndex = 0;
	MASTER_signed_maxint totalProd = 0;
	MASTER_signed_maxint totalSum = maxProduct_DFS(root, subTreeSums, &index);
	for (; jndex < index; jndex += 1)
		MASTER_IMAX(totalProd, subTreeSums[jndex] * (totalSum - subTreeSums[jndex]));
	free(subTreeSums);
	return totalProd % 1000000007;
}

/* #! 1390. Four Divisors !# */ UI4
MASTER_Algolib_SumOfFourDivisors( const UI4 * numbers, const UI4 number_count ) {
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

/* #! 1458. Max Dot Product of Two Subsequences !# */ SI4
MASTER_Algolib_MaximumDotProduct( const SI4 * const nums1, const UI4 nums1Size, const SI4 * const nums2, const UI4 nums2Size ) {
	UI4 index = 0;
	UI4 jndex;
	SI4 * dp;
	SI4 answer = MASTER_SI4_MIN;
	SI4 product;
	const UI4 length = nums2Size + 1;
	dp = (SI4 *)MASTER_MALLOC(sizeof(SI4) * (nums1Size + 1) * length);
	for (; index < (nums1Size + 1) * length; index += 1)
		dp[index] = MASTER_SI4_MIN;
	for (index = 1; index <= nums1Size; index += 1) {
		for (jndex = 1; jndex <= nums2Size; jndex += 1) {
			dp[index * length + jndex] = product = nums1[index - 1] * nums2[jndex - 1];
			MASTER_IMAX(dp[index * length + jndex], product + MASTER_MAX(dp[(index - 1) * length + (jndex - 1)], 0));
			MASTER_IMAX(dp[index * length + jndex], dp[(index - 1) * length + jndex]);
			MASTER_IMAX(dp[index * length + jndex], dp[index * length + (jndex - 1)]);
		}
	}
	answer = dp[nums1Size * length + nums2Size];
	MASTER_FREE(dp);
	return answer;
}


/* #! 1716. Calculate Money in Leetcode Bank !# */ SI4
MASTER_Algolib_TotalMoney( const SI4 value ) {
	const SI4 weeks = value / 7;
	const SI4 days = value % 7;
	return (28 * weeks + 7 * weeks * (weeks - 1) / 2) + days * (2 * (weeks + 1) + (days - 1)) / 2;
}

#define MASTER_ALGOLIB_MINIMUMXORSUM_MAXN 14
#define MASTER_ALGOLIB_MINIMUMXORSUM_MAXMASK (1 << MASTER_ALGOLIB_MINIMUMXORSUM_MAXN)

/* #! 1879. Minimum XOR Sum of Two Arrays !# */ SI4
MASTER_Algolib_MinimumXorSum( const UI4 * const nums1, const UI4 * const nums2, const UI4 numsSize ) {
	const UI4 fullMask = 1 << numsSize;
	UI4 dp[MASTER_ALGOLIB_MINIMUMXORSUM_MAXMASK] = { 0 };
	UI4 mask = 1;
	UI4 nextMask;
	UI4 cost;
	UI4 index;
	UI4 jndex;
	for (; mask < fullMask; mask += 1)
		dp[mask] = MASTER_SI4_MAX;
	for (mask = 0; mask < fullMask; mask += 1) {
		index = MASTER_Bit_CountOnes4(mask);
		if (index >= numsSize) continue;
		for (jndex = 0; jndex < numsSize; jndex += 1) {
			if ((mask & (1 << jndex)) == 0) {
				nextMask = mask | (1 << jndex);
				cost = dp[mask] + (nums1[index] ^ nums2[jndex]);
				if (cost < dp[nextMask])
					dp[nextMask] = cost;
			}
		}
	}
	return dp[fullMask - 1];
}

/* #! 1895. Largest Magic Square !# */ SI4
MASTER_Algolib_LargestMagicSquare( const SI4** grid, const SI4 gridSize, const SI4 * gridColSize ) {
    const SI4 cols = *gridColSize;
    const SI4 rows = gridSize;
    SI4 * prefixRows = (SI4 *)MASTER_CALLOC((cols + 1) * (rows + 1), sizeof(SI4));
    SI4 * prefixCols = (SI4 *)MASTER_CALLOC((cols + 1) * (rows + 1), sizeof(SI4));
    SI4 * prefixDiagUp = (SI4 *)MASTER_CALLOC((cols + 1) * (rows + 1), sizeof(SI4));
    SI4 * prefixDiagDown = (SI4 *)MASTER_CALLOC((cols + 1) * (rows + 1), sizeof(SI4));
    SI4 index = 1;
    SI4 jndex;
    SI4 kndex;
    SI4 lndex;
    SI4 answer = 0;
    SI4 sumValue;
    UI1 compare;
    for (; index <= rows; index += 1) {
        for (jndex = 1; jndex <= cols; jndex += 1) {
            prefixRows[index * cols + jndex] += grid[index - 1][jndex - 1] + prefixRows[index * cols + jndex - 1];
            prefixCols[index * cols + jndex] += grid[index - 1][jndex - 1] + prefixCols[(index - 1) * cols + jndex];
            prefixDiagUp[index * cols + jndex] += grid[index - 1][jndex - 1] + prefixDiagUp[(index - 1) * cols + jndex + 1];
            prefixDiagDown[index * cols + jndex] += grid[index - 1][jndex - 1] + prefixDiagDown[(index - 1) * cols + jndex - 1];
        }
    }
    for (index = 1; index <= rows; index += 1) {
        for (jndex = 1; jndex <= cols; jndex += 1) {
            for (kndex = MASTER_MIN(rows - index, cols - jndex); kndex > answer; kndex -= 1) {
                sumValue = prefixDiagDown[(index + kndex) * cols + jndex + kndex] - prefixDiagDown[(index - 1) * cols + jndex - 1];
                compare = sumValue == prefixDiagUp[(index + kndex) * cols + jndex] - prefixDiagUp[(index - 1) * cols + jndex + kndex + 1];
                for (lndex = 0; lndex <= kndex && compare == 1; lndex += 1) {
                    compare &= sumValue == prefixRows[(index + lndex) * cols + jndex + kndex] - prefixRows[(index + lndex) * cols + jndex - 1] && 
                               sumValue == prefixCols[(index + kndex) * cols + jndex + lndex] - prefixCols[(index - 1) * cols + jndex + lndex];
                }
                if (compare == 1)
                    answer = kndex;
            }
        }
    }
    MASTER_FREE(prefixRows);
    MASTER_FREE(prefixCols);
    MASTER_FREE(prefixDiagUp);
    MASTER_FREE(prefixDiagDown);
    return answer + 1;
}


/* #! 1975. Maximum Matrix Sum !# */ SI4
MASTER_Algolib_MaximumMatrixSum( const SI4 * const * const matrix, const UI4 matrixSize ) {
	SI4 totalSum = 0;
	UI1 negParity = 0;
	SI4 minValue = MASTER_SI4_MAX;
	UI4 index = 0;
	UI4 jndex;
	SI4 value;
	for (; index < matrixSize; index += 1) {
		for (jndex = 0; jndex < matrixSize; jndex += 1) {
			value = matrix[index][jndex];
			negParity ^= value < 0;
			value = MASTER_ABS(value);
			totalSum += value;
			if (minValue > value)
				minValue = value;
		}
	}
	if (negParity == 0)
		return totalSum;
	return totalSum - minValue * 2;
}

/* #! 2552. Count Increasing Quadruplets !# */ MASTER_signed_maxint
MASTER_Algolib_CountQuadruplets( const SI4 * numbers, const UI4 numsSize ) {
	MASTER_signed_maxint total = 0;
	MASTER_signed_maxint prevSmall;
	UI4 * less = (UI4 *)calloc(numsSize, sizeof(UI4));
	UI4 jndex = 0;
	UI4 kndex;
	for (; jndex < numsSize; jndex += 1) {
		prevSmall = 0;
		for (kndex = 0; kndex < jndex; kndex += 1)
			if (numbers[kndex] < numbers[jndex]) {
				prevSmall += 1;
				total += less[kndex];
			} otherwise (numbers[kndex] > numbers[jndex])
				less[kndex] += prevSmall;
	}
	free(less);
	return total;
}

/* #! 2570. Merge Two 2D Arrays by Summing Values !# */ SI4**
MASTER_Algolib_MergeArrays( const SI4** nums1, const UI4 nums1Size, const SI4** nums2, const UI4 nums2Size, SI4 * returnSize, SI4** returnColumnSizes ) {
	UI4 kndex = 0;
	UI4 index = 0;
	UI4 jndex = 0;
	SI4** output = (SI4**)MASTER_MALLOC((nums1Size + nums2Size) * sizeof(SI4 *));
	*returnColumnSizes = (SI4 *)MASTER_MALLOC((nums1Size + nums2Size) * sizeof(SI4));
	for (;; kndex += 1) {
		if (index >= nums1Size && jndex >= nums2Size) break;
		output[kndex] = (SI4 *)malloc(2 * sizeof(SI4));
		(*returnColumnSizes)[kndex] = 2;
		if (index < nums1Size && ((jndex < nums2Size && nums1[index][0] < nums2[jndex][0]) || jndex >= nums2Size)) {
			output[kndex][0] = nums1[index][0];
			output[kndex][1] = nums1[index][1];
			index += 1;
		} otherwise (jndex < nums2Size && ((index < nums1Size && nums1[index][0] > nums2[jndex][0]) || index >= nums1Size)) {
			output[kndex][0] = nums2[jndex][0];
			output[kndex][1] = nums2[jndex][1];
			jndex += 1;
		} otherwise (index < nums1Size && jndex < nums2Size && nums1[index][0] == nums2[jndex][0]) {
			output[kndex][0] = nums1[index][0];
			output[kndex][1] = nums1[index][1] + nums2[jndex][1];
			index += 1;
			jndex += 1;
		}
	}
	*returnSize = kndex;
	return output;
}

#define MASTER_ALGOLIB_KNIGHTMAXIMUMMOVES_BOARDSIZE 50

typedef struct {
	SI4 row;
	SI4 column;
} MASTER_Algolib_KnightMaximumMoves_Point;

MASTER_PREFER_STATIC const SI1 MASTER_Algolib_KnightMaximumMoves_KnightMoveRow[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
MASTER_PREFER_STATIC const SI1 MASTER_Algolib_KnightMaximumMoves_KnightMoveColumn[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };

MASTER_PREFER_STATIC void
MASTER_Algolib_KnightMaximumMoves_BFSDistances( const SI4 startRow, const SI4 startColumn, SI4 board_dist[MASTER_ALGOLIB_KNIGHTMAXIMUMMOVES_BOARDSIZE][MASTER_ALGOLIB_KNIGHTMAXIMUMMOVES_BOARDSIZE] ) {
	MASTER_Algolib_KnightMaximumMoves_Point queue[MASTER_ALGOLIB_KNIGHTMAXIMUMMOVES_BOARDSIZE * MASTER_ALGOLIB_KNIGHTMAXIMUMMOVES_BOARDSIZE];
	MASTER_Algolib_KnightMaximumMoves_Point current;
	UI4 queueHead = 0;
	UI4 queueTail = 1;
	UI1 index;
	SI1 row = 0;
	SI1 column;
	SI1 newRow;
	SI1 newColumn;
	UI4 distance;
	for (; row < MASTER_ALGOLIB_KNIGHTMAXIMUMMOVES_BOARDSIZE; row += 1)
		for (column = 0; column < MASTER_ALGOLIB_KNIGHTMAXIMUMMOVES_BOARDSIZE; column += 1)
			board_dist[row][column] = -1;
	board_dist[startRow][startColumn] = 0;
	queue[0].row = startRow;
	queue[0].column = startColumn;
	while (queueHead < queueTail) {
		current = queue[queueHead];
		queueHead += 1;
		row = current.row;
		column = current.column;
		distance = board_dist[row][column];
		for (index = 0; index < 8; index += 1) {
			newRow = row + MASTER_Algolib_KnightMaximumMoves_KnightMoveRow[index];
			newColumn = column + MASTER_Algolib_KnightMaximumMoves_KnightMoveColumn[index];
			if (newRow >= 0 && newRow < MASTER_ALGOLIB_KNIGHTMAXIMUMMOVES_BOARDSIZE && newColumn >= 0 && newColumn < MASTER_ALGOLIB_KNIGHTMAXIMUMMOVES_BOARDSIZE && board_dist[newRow][newColumn] == -1) {
				board_dist[newRow][newColumn] = distance + 1;
				queue[queueTail].row = newRow;
				queue[queueTail].column = newColumn;
				queueTail += 1;
			}
		}
	}
}

MASTER_PREFER_STATIC SI4
MASTER_Algolib_KnightMaximumMoves_Solve( UI4 mask, UI4 lastIndex, SI2 * const memoization, const SI4** distances, const UI4 pawnCount ) {
	UI4 movesMade = pawnCount - MASTER_Bit_CountOnes4(mask);
	UI1 isAlice = !(movesMade & 1);
	SI4 bestValue = (isAlice) ? (-1) : (MASTER_SI2_MAX);
	SI4 value;
	UI4 index = 0;
	if (mask == 0) return 0;
	if (memoization[mask * (pawnCount + 1) + lastIndex] != -1)
		return memoization[mask * (pawnCount + 1) + lastIndex];
	for (; index < pawnCount; index += 1) {
		if ((mask & (1 << index)) == 0) continue;
		value = distances[lastIndex][index] + MASTER_Algolib_KnightMaximumMoves_Solve(mask ^ (1 << index), index, memoization, distances, pawnCount);
		bestValue = ((isAlice) ? (value > bestValue) : (value < bestValue)) ? (value) : (bestValue);
	}
	memoization[mask * (pawnCount + 1) + lastIndex] = bestValue;
	return bestValue;
}

/* #! 3283. Maximum Number of Moves to Kill All Pawns !# */ SI4
MASTER_Algolib_KnightMaximumMoves( const SI4 knightX, const SI4 knightY, const SI4** const positions, const UI4 positionsSize ) {
	UI4 index = 0;
	UI1 jndex;
	SI4 boardDist[MASTER_ALGOLIB_KNIGHTMAXIMUMMOVES_BOARDSIZE][MASTER_ALGOLIB_KNIGHTMAXIMUMMOVES_BOARDSIZE];
	UI4 initMask = (1 << positionsSize) - 1;
	UI4 answer;
	const UI4 memoSize = (1 << positionsSize) * (positionsSize + 1);
	SI2 * memoization = (SI2 *)MASTER_MALLOC(memoSize * sizeof(SI2));
	SI4 distances[16][16];
	for (; index < positionsSize; index += 1) {
		MASTER_Algolib_KnightMaximumMoves_BFSDistances(positions[index][0], positions[index][1], boardDist);
		for (jndex = 0; jndex < positionsSize; jndex += 1)
			distances[index][jndex] = boardDist[positions[jndex][0]][positions[jndex][1]];
		distances[index][positionsSize] = boardDist[knightX][knightY];
	}
	MASTER_Algolib_KnightMaximumMoves_BFSDistances(knightX, knightY, boardDist);
	for (jndex = 0; jndex < positionsSize; jndex += 1)
		distances[index][jndex] = boardDist[positions[jndex][0]][positions[jndex][1]];
	distances[positionsSize][positionsSize] = 0;
	for (index = 0; index < memoSize; index += 1)
		memoization[index] = -1;
	answer = MASTER_Algolib_KnightMaximumMoves_Solve(initMask, positionsSize, memoization, (const SI4**)distances, positionsSize);
	MASTER_FREE(memoization);
	return answer;
}

typedef struct {
	SI4 x1;
	SI4 y1;
	SI4 x2;
	SI4 y2;
} MASTER_Algolib_LargestSquareArea_Rectangle;

MASTER_PREFER_STATIC SI4
MASTER_Algolib_LargestSquareArea_RectangleCompare( const void * const data1, const void * const data2 ) {
	return ((const MASTER_Algolib_LargestSquareArea_Rectangle *)data1)->x1 - ((const MASTER_Algolib_LargestSquareArea_Rectangle *)data2)->x1;
}

/* #! 3047. Find the Largest Area of Square Inside Two Rectangles !# */ MASTER_signed_maxint
MASTER_Algolib_LargestSquareArea( SI4** bottomLeft, SI4** topRight, const UI4 length ) {
	MASTER_Algolib_LargestSquareArea_Rectangle rectangle1;
	MASTER_Algolib_LargestSquareArea_Rectangle rectangle2;
	MASTER_Algolib_LargestSquareArea_Rectangle * rectangles = (MASTER_Algolib_LargestSquareArea_Rectangle *)MASTER_CALLOC(length, sizeof(MASTER_Algolib_LargestSquareArea_Rectangle));
	SI4 maxSide = 0;
	SI4 width;
	SI4 height;
	UI4 index = 0;
	UI4 jndex;
	for (; index < length; index += 1) {
		rectangles[index].x1 = bottomLeft[index][0];
		rectangles[index].y1 = bottomLeft[index][1];
		rectangles[index].x2 = topRight[index][0];
		rectangles[index].y2 = topRight[index][1];
	}
	qsort(rectangles, length, sizeof(MASTER_Algolib_LargestSquareArea_Rectangle), MASTER_Algolib_LargestSquareArea_RectangleCompare);
	for (index = 0; index < length; index += 1) {
		rectangle1 = rectangles[index];
		for (jndex = index + 1; jndex < length; jndex += 1) {
			rectangle2 = rectangles[jndex];
			if (rectangle2.x1 >= rectangle1.x2) break;
			width = MASTER_MIN(rectangle1.x2, rectangle2.x2) - MASTER_MAX(rectangle1.x1, rectangle2.x1);
			height = MASTER_MIN(rectangle1.y2, rectangle2.y2) - MASTER_MAX(rectangle1.y1, rectangle2.y1);
			if (width > 0 && height > 0)
				MASTER_IMAX(maxSide, MASTER_MIN(width, height));
		}
	}
	MASTER_FREE(rectangles);
	return (MASTER_signed_maxint)maxSide * (MASTER_signed_maxint)maxSide;
}

typedef struct {
	SI4 y;
	SI4 l;
} MASTER_Algolib_SeparateSquares_Corner;

MASTER_PREFER_STATIC SI4
MASTER_Algolib_SeparateSquares_CornerComparator( const void * const data1, const void * const data2 ) {
	const MASTER_Algolib_SeparateSquares_Corner * const corner1 = (const MASTER_Algolib_SeparateSquares_Corner *)data1;
	const MASTER_Algolib_SeparateSquares_Corner * const corner2 = (const MASTER_Algolib_SeparateSquares_Corner *)data2;
	return corner1->y - corner2->y;
}

/* #! 3453. Separate Squares I !# */ double
MASTER_Algolib_SeparateSquares( const SI4** squares, const UI4 squaresSize ) {
	UI4 index = 0;
	double total = 0;
	double half;
	double currentRate = 0;
	double areaBelow = 0;
	double segArea;
	double prevY;
	double height;
	MASTER_Algolib_SeparateSquares_Corner * corners = (MASTER_Algolib_SeparateSquares_Corner *)MASTER_CALLOC(squaresSize << 1, sizeof(MASTER_Algolib_SeparateSquares_Corner));
	for (; index < squaresSize; index += 1) {
		corners[index << 1].y = squares[index][1];
		corners[index << 1].l = squares[index][2];
		corners[(index << 1) | 1].y = squares[index][1] + squares[index][2];
		corners[(index << 1) | 1].l = -squares[index][2];
		total += (double)squares[index][2] * squares[index][2];
	}
	qsort(corners, squaresSize << 1, sizeof(MASTER_Algolib_SeparateSquares_Corner), MASTER_Algolib_SeparateSquares_CornerComparator);
	half = total / 2.0;
	prevY = corners[0].y;
	for (index = 0; index < squaresSize << 1; index += 1) {
		height = corners[index].y - prevY;
		if (height > 0) {
			segArea = currentRate * height;
			if (segArea + areaBelow >= half) {
				MASTER_FREE(corners);
				return prevY + (half - areaBelow) / currentRate;
			}
			areaBelow += segArea;
		}
		currentRate += corners[index].l;
		prevY = corners[index].y;
	}
	MASTER_PREFER_UNREACHABLE;
	return 0.0 / 0.0;
}

/* #! 3500. Minimum Cost to Divide Array Into Subarrays !# */ MASTER_signed_maxint
MASTER_Algolib_MinimumCost( const SI4 * const nums, const SI4 * const cost, const UI4 length, const SI4 k ) {
    MASTER_signed_maxint * deque = (MASTER_signed_maxint *)MASTER_CALLOC(length + 2, sizeof(MASTER_signed_maxint));
    MASTER_signed_maxint * prefixNums = (MASTER_signed_maxint *)MASTER_CALLOC(length + 1, sizeof(MASTER_signed_maxint));
    MASTER_signed_maxint * prefixCosts = (MASTER_signed_maxint *)MASTER_CALLOC(length + 1, sizeof(MASTER_signed_maxint));
    MASTER_signed_maxint curValue;
    UI4 index = 1;
    UI4 jndex;
    for (; index <= length; index += 1) {
        prefixNums[index] = prefixNums[index - 1] + nums[index - 1];
        prefixCosts[index] = prefixCosts[index - 1] + cost[index - 1];
    }
    for (index = length; index > 0; index -= 1)
        deque[index] = (MASTER_signed_maxint)(prefixNums[length] + k) * (MASTER_signed_maxint)(prefixCosts[length] - prefixCosts[index - 1]);
    for (index = length - 1; index > 0; index -= 1) {
        curValue = deque[index + 1] + (MASTER_signed_maxint)(prefixCosts[length] - prefixCosts[index]) * k;
        for (jndex = index; jndex > 0; jndex -= 1) {
            deque[jndex] = MASTER_MIN(deque[jndex], (MASTER_signed_maxint)(prefixNums[index] + k) * (MASTER_signed_maxint)(prefixCosts[index] - prefixCosts[jndex - 1]) + curValue);
        }
    }
    curValue = deque[1];
    MASTER_FREE(deque);
    MASTER_FREE(prefixNums);
    MASTER_FREE(prefixCosts);
    return curValue;
}

/* #! 3809. Best Reachable Tower !# */ SI4 *
MASTER_Algolib_BestTower( const SI4** towers, const UI4 towersSize, const SI4 * center, const SI4 radius ) {
	SI4 * bestCoord = (SI4 *)MASTER_CALLOC(2, sizeof(SI4));
	SI4 bestQuality = -1;
	UI4 index = 0;
	SI4 distance;
	bestCoord[0] = bestCoord[1] = -1;
	for (; index < towersSize; index += 1) {
		distance = abs(towers[index][0] - center[0]) + abs(towers[index][1] - center[1]);
		if (distance <= radius) {
			if (towers[index][2] > bestQuality) {
				bestQuality = towers[index][2];
				memcpy(bestCoord, towers[index], 2 * sizeof(UI4));
			} otherwise (towers[index][2] == bestQuality)
				if (towers[index][0] < bestCoord[0] || (towers[index][0] == bestCoord[0] && towers[index][1] < bestCoord[1])) {
					memcpy(bestCoord, towers[index], 2 * sizeof(UI4));
			}
		}
	}
	return bestCoord;
}

/* #! 3810. Minimum Operations to Reach Target Array !# */ SI4
MASTER_Algolib_MinimumOperations( const SI4 * nums, const SI4 * target, const UI4 length ) {
	SI1 * differentValues = (SI1 *)MASTER_CALLOC(100001, sizeof(SI1));
	UI4 index = 0;
	UI4 counter = 0;
	for (; index < length; index += 1) {
		if (nums[index] != target[index]) {
			if (differentValues[nums[index]] == 0)
				counter += 1;
			differentValues[nums[index]] = 1;
		}
	}
	MASTER_FREE(differentValues);
	return counter;
}

/* #! 3811. Number of Alternating XOR Partitions !# */ SI4
MASTER_Algolib_AlternatingXor( const SI4 * const nums, const UI4 numsSize, const SI4 target1, const SI4 target2 ) {
	UI4 count1[131072];
	UI4 count2[131072];
	UI4 ways1 = 0;
	UI4 ways2 = 0;
	UI4 curX = 0;
	UI4 index = 0;
	MASTER_MEMSET(count1, 0, 131072 * sizeof(UI4));
	MASTER_MEMSET(count2, 0, 131072 * sizeof(UI4));
	count2[0] = 1;
	for (; index < numsSize; index += 1) {
		curX ^= nums[index];
		ways2 = count1[curX ^ target2];
		ways1 = count2[curX ^ target1];
		count1[curX] = (count1[curX] + ways1) % 1000000007;
		count2[curX] = (count2[curX] + ways2) % 1000000007;
	}
	return (ways1 + ways2) % 1000000007;
}

typedef struct {
	UI4 node;
	UI4 index;
} MASTER_Algolib_MinimumFlips_NodeState;

MASTER_PREFER_STATIC UI1
MASTER_Algolib_MinimumFlips_DFS( SI4 * const answer, UI4 * const answerSize, const char * const difference, const MASTER_Algolib_MinimumFlips_NodeState * const * state, const UI4 * const stateSizes, const UI4 nodeU, const UI4 nodeP ) {
	UI1 change = 0;
	UI4 index = 0;
	for (; index < stateSizes[nodeU]; index += 1) {
		if (state[nodeU][index].node == nodeP) continue;
		if (MASTER_Algolib_MinimumFlips_DFS(answer, answerSize, difference, state, stateSizes, state[nodeU][index].node, nodeU)) {
			change ^= 1;
			answer[*answerSize] = state[nodeU][index].index;
			*answerSize += 1;
		}
	}
	return difference[nodeU] ^ change;
}

MASTER_PREFER_STATIC SI4
MASTER_Algolib_MinimumFlips_Comparator( const void * const data1, const void * const data2 ) {
	return *(const SI4 *)data1 - *(const SI4 *)data2;
}

/* #! 3812. Minimum Edge Toggles on a Tree !# */ SI4 *
MASTER_Algolib_MinimumFlips( UI4 n, SI4** edges, UI4 edgesSize, char * start, char * target, SI4 * returnSize ) {
	MASTER_Algolib_MinimumFlips_NodeState** state = (MASTER_Algolib_MinimumFlips_NodeState**)MASTER_CALLOC(n << 1, sizeof(MASTER_Algolib_MinimumFlips_NodeState *));
	UI4 * stateSizes = (UI4 *)MASTER_CALLOC(n << 1, sizeof(UI4 *));
	SI4 * answer = (SI4 *)calloc(n, sizeof(SI4));
	UI4 answerSize = 0;
	UI4 index = 0;
	UI4 node1;
	UI4 node2;
	memset(state, 0, (n << 1) * sizeof(MASTER_Algolib_MinimumFlips_NodeState *));
	memset(stateSizes, 0, (n << 1) * sizeof(UI4 *));
	for (; start[index] != '\0'; index += 1)
		start[index] = start[index] != target[index];
	for (index = 0; index < edgesSize; index += 1) {
		node1 = edges[index][0];
		node2 = edges[index][1];
		if ((stateSizes[node1] & 0x1F) == 0)
			state[node1] = (MASTER_Algolib_MinimumFlips_NodeState *)MASTER_REALLOC(state[node1], (stateSizes[node1] + 32) * sizeof(MASTER_Algolib_MinimumFlips_NodeState));
		state[node1][stateSizes[node1]].node = node2;
		state[node1][stateSizes[node1]].index = index;
		stateSizes[node1] += 1;
		if ((stateSizes[node2] & 0x1F) == 0)
			state[node2] = (MASTER_Algolib_MinimumFlips_NodeState *)MASTER_REALLOC(state[node2], (stateSizes[node2] + 32) * sizeof(MASTER_Algolib_MinimumFlips_NodeState));
		state[node2][stateSizes[node2]].node = node1;
		state[node2][stateSizes[node2]].index = index;
		stateSizes[node2] += 1;
	}
	if (MASTER_Algolib_MinimumFlips_DFS(answer, &answerSize, start, (const MASTER_Algolib_MinimumFlips_NodeState * const *)state, stateSizes, 0, -1)) {
		answer[0] = -1;
		*returnSize = 1;
	} else {
		qsort(answer, answerSize, sizeof(SI4), MASTER_Algolib_MinimumFlips_Comparator);
		*returnSize = answerSize;
	}
	for (index = 0; index < n; index += 1)
		MASTER_FREE(state[index]);
	MASTER_FREE(state);
	MASTER_FREE(stateSizes);
	return answer;
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

OSI
MASTER_Algolib_RoundSqrt( const OSI value ) {
	OSI estimate = value;
	if (value < 0) return -1;
	while (estimate > value / estimate)
		estimate = (estimate + value / estimate) >> 1;
	return estimate + (MASTER_SQUARE(estimate + 1) - value < value - MASTER_SQUARE(estimate));
}

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

/* #! OneShot Hash Functions !# */

MASTER_maxint
MASTER_Algolib_DJB2( const UI1 * bytes, MASTER_maxint length ) {
	MASTER_maxint hash_value = 5381;
	while (length > 0) {
		hash_value = hash_value * 33 + *bytes; /* #! or ^ !# */
		bytes += 1;
		length -= 1;
	}
	return hash_value;
}

MASTER_maxint
MASTER_Algolib_SDBM( const UI1 * bytes, MASTER_maxint length ) {
	MASTER_maxint hash_value = 0;
	while (length > 0) {
		hash_value = hash_value * 65599 + *bytes;
		bytes += 1;
		length -= 1;
	}
	return hash_value;
}
/* #! TODO : FSM !# */
UI4
MASTER_Algolib_MurmurHash1( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint length, const UI4 seed_value ) {
	UI4 hash_value = seed_value ^ (length * 0xC6A4A793);
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul) return 0;
	while (estimated >= 4) {
		hash_value += MASTER_TOLE4(*(const UI4 *)ui1_data);
		hash_value *= 0xC6A4A793;
		hash_value ^= hash_value >> 16;
		ui1_data += 4;
		estimated -= 4;
	}
	if (estimated >= 3)
		hash_value += ui1_data[2] << 16;
	if (estimated >= 2)
		hash_value += ui1_data[1] << 8;
	if (estimated >= 1) {
		hash_value += ui1_data[0];
		hash_value *= 0xC6A4A793;
		hash_value ^= hash_value >> 16;
	}
	hash_value *= 0xC6A4A793;
	hash_value ^= hash_value >> 10;
	hash_value *= 0xC6A4A793;
	hash_value ^= hash_value >> 17;
	return hash_value;
}

UI4
MASTER_Algolib_MurmurHash1_Aligned( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint length, const UI4 seed_value ) {
	union {
		const void * MASTER_PREFER_RESTRICT bytes;
		MASTER_maxint value;
	} bytesUnion;
	UI4 hash_value = seed_value ^ (length * 0xC6A4A793);
	UI1 align;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul) return 0;
	bytesUnion.bytes = bytes;
	align = bytesUnion.value & 3;
	if (align > 0 && length >= 4) {
		const UI1 shiftLeft = (4 - align) << 3;
		const UI1 shiftRight = align << 3;
		UI4 helder;
		UI4 temp_value = 0;
		UI1 pack;
		if (align <= 1)
			temp_value |= ui1_data[2] << 16;
		if (align <= 2)
			temp_value |= ui1_data[1] << 8;
		if (align <= 3)
			temp_value |= ui1_data[0];
		temp_value <<= align << 3;
		ui1_data += 4 - align;
		estimated -= 4 - align;
		while (estimated >= 4) {
			helder = MASTER_TOLE4(*(const UI4 *)ui1_data);
			temp_value = (temp_value >> shiftRight) | (helder << shiftLeft);
			hash_value += temp_value;
			hash_value *= 0xC6A4A793;
			hash_value ^= hash_value >> 16;
			temp_value = helder;
			ui1_data += 4;
			estimated -= 4;
		}
		pack = MASTER_MIN(estimated, align);
		helder = 0;
		if (pack >= 3)
			helder |= ui1_data[2] << 16;
		if (pack >= 2)
			helder |= ui1_data[1] << 8;
		if (pack >= 1)
			helder |= ui1_data[0];
		hash_value += (temp_value >> shiftRight) | (helder << shiftLeft);
		hash_value *= 0xC6A4A793;
		hash_value ^= hash_value >> 16;
		ui1_data += pack;
		estimated -= pack;
	} else
		while (estimated >= 4) {
			hash_value += MASTER_TOLE4(*(const UI4 *)ui1_data);
			hash_value *= 0xC6A4A793;
			hash_value ^= hash_value >> 16;
			ui1_data += 4;
			estimated -= 4;
		}
	if (estimated >= 3)
		hash_value += ui1_data[2] << 16;
	if (estimated >= 2)
		hash_value += ui1_data[1] << 8;
	if (estimated >= 1) {
		hash_value += ui1_data[0];
		hash_value *= 0xC6A4A793;
		hash_value ^= hash_value >> 16;
	}
	hash_value *= 0xC6A4A793;
	hash_value ^= hash_value >> 10;
	hash_value *= 0xC6A4A793;
	hash_value ^= hash_value >> 17;
	return hash_value;
}

#if MASTER_64_AVAILABLE
/* #! TODO : FSM !# */
UI8
MASTER_Algolib_MurmurHash64A( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint length, const UI8 seed_value ) {
	UI8 hash_value = (length * 0xC6A4A7935BD1E995) ^ seed_value;
	UI8 helder;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul) return 0;
	while (estimated >= 8) {
		helder = MASTER_TOLE8(*(const UI8 *)ui1_data);
		helder *= 0xC6A4A7935BD1E995;
		helder ^= helder >> 47;
		helder *= 0xC6A4A7935BD1E995;
		hash_value ^= helder;
		hash_value *= 0xC6A4A7935BD1E995;
		ui1_data += 8;
		estimated -= 8;
	}
	if (estimated >= 7)
		hash_value ^= ((UI8)ui1_data[6]) << 48;
	if (estimated >= 6)
		hash_value ^= ((UI8)ui1_data[5]) << 40;
	if (estimated >= 5)
		hash_value ^= ((UI8)ui1_data[4]) << 32;
	if (estimated >= 4)
		hash_value ^= ((UI8)ui1_data[3]) << 24;
	if (estimated >= 3)
		hash_value ^= ((UI8)ui1_data[2]) << 16;
	if (estimated >= 2)
		hash_value ^= ((UI8)ui1_data[1]) << 8;
	if (estimated >= 1) {
		hash_value ^= ((UI8)ui1_data[0]);
		hash_value *= 0xC6A4A7935BD1E995;
	}
	hash_value ^= hash_value >> 47;
	hash_value *= 0xC6A4A7935BD1E995;
	hash_value ^= hash_value >> 47;
	return hash_value;
}

/* #! TODO : FSM !# */
UI8
MASTER_Algolib_MurmurHash64B( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint length, const UI8 seed_value ) {
	UI4 hash_value_1 = (SI4)seed_value ^ (SI4)length;
	UI4 hash_value_2 = seed_value >> 32;
	UI4 helder_1;
	UI4 helder_2;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul) return 0;
	while (estimated >= 8) {
		helder_1 = MASTER_TOLE4(((const UI4 *)ui1_data)[0]);
		helder_2 = MASTER_TOLE4(((const UI4 *)ui1_data)[1]);
		helder_1 *= 0x5BD1E995;
		helder_2 *= 0x5BD1E995;
		helder_1 ^= helder_1 >> 24;
		helder_2 ^= helder_2 >> 24;
		helder_1 *= 0x5BD1E995;
		helder_2 *= 0x5BD1E995;
		hash_value_1 *= 0x5BD1E995;
		hash_value_2 *= 0x5BD1E995;
		hash_value_1 ^= helder_1;
		hash_value_2 ^= helder_2;
		ui1_data += 8;
		estimated -= 8;
	}
	if (estimated >= 4) {
		helder_1 = MASTER_TOLE4(*(const UI4 *)ui1_data);
		helder_1 *= 0x5BD1E995;
		helder_1 ^= helder_1 >> 24;
		helder_1 *= 0x5BD1E995;
		hash_value_1 *= 0x5BD1E995;
		hash_value_1 ^= helder_1;
		ui1_data += 4;
		estimated &= 3;
	}
	if (estimated >= 3)
		hash_value_2 ^= ui1_data[2] << 16;
	if (estimated >= 2)
		hash_value_2 ^= ui1_data[1] << 8;
	if (estimated >= 1) {
		hash_value_2 ^= ui1_data[0];
		hash_value_2 *= 0x5BD1E995;
	}
	hash_value_1 ^= hash_value_2 >> 18;
	hash_value_1 *= 0x5BD1E995;
	hash_value_2 ^= hash_value_1 >> 22;
	hash_value_2 *= 0x5BD1E995;
	hash_value_1 ^= hash_value_2 >> 17;
	hash_value_1 *= 0x5BD1E995;
	hash_value_2 ^= hash_value_1 >> 19;
	hash_value_2 *= 0x5BD1E995;
	return ((UI8)hash_value_1 << 32) | hash_value_2;
}
#endif /* #! 64 Bits !# */

#define MASTER_ALGOLIB_MURMURHASH2A_MIX( hash_value, helder ) do { \
		(helder) *= 0x5BD1E995; \
		(helder) ^= (helder) >> 24; \
		(helder) *= 0x5BD1E995; \
		(hash_value) *= 0x5BD1E995; \
		(hash_value) ^= (helder); \
	} while (0)

UI4
MASTER_Algolib_MurmurHash2( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint length, const UI4 seed_value ) {
	UI4 hash_value = length ^ seed_value;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	UI4 helder;
	while (estimated >= 4) {
		helder = MASTER_TOLE4(*(const UI4 *)ui1_data);
		MASTER_ALGOLIB_MURMURHASH2A_MIX(hash_value, helder);
		ui1_data += 4;
		estimated -= 4;
	}
	if (estimated >= 3)
		hash_value ^= ui1_data[2] << 16;
	if (estimated >= 2)
		hash_value ^= ui1_data[1] << 8;
	if (estimated >= 1) {
		hash_value ^= ui1_data[0];
		hash_value *= 0x5BD1E995;
	}
	hash_value ^= hash_value >> 13;
	hash_value *= 0x5BD1E995;
	hash_value ^= hash_value >> 15;
	return hash_value;
}

UI4
MASTER_Algolib_MurmurHash2A( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint length, const UI4 seed_value ) {
	UI4 hash_value = seed_value;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	union {
		UI4 unsign;
		SI4 sign;
	} helder;
	if (bytes == nul) return 0;
	while (estimated >= 4) {
		helder.unsign = MASTER_TOLE4(*(const UI4 *)ui1_data);
		MASTER_ALGOLIB_MURMURHASH2A_MIX(hash_value, helder.unsign);
		ui1_data += 4;
		estimated -= 4;
	}
	helder.unsign = 0;
	if (estimated >= 3)
		helder.unsign |= ui1_data[2] << 16;
	if (estimated >= 2)
		helder.unsign |= ui1_data[1] << 8;
	if (estimated >= 1)
		helder.unsign |= ui1_data[0];
	MASTER_ALGOLIB_MURMURHASH2A_MIX(hash_value, helder.unsign);
	helder.sign = (SI4)length;
	MASTER_ALGOLIB_MURMURHASH2A_MIX(hash_value, helder.sign);
	hash_value ^= hash_value >> 13;
	hash_value *= 0x5BD1E995;
	hash_value ^= hash_value >> 15;
	return hash_value;
}

UI4
MASTER_Algolib_MurmurHash2_Aligned( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint length, const UI4 seed_value ) {
	union {
		const void * MASTER_PREFER_RESTRICT bytes;
		MASTER_maxint value;
	} bytesUnion;
	UI4 hash_value = length ^ seed_value;
	UI4 helder;
	UI1 align;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul) return 0;
	bytesUnion.bytes = bytes;
	align = bytesUnion.value & 3;
	if (align > 0 && length >= 4) {
		const UI1 shiftLeft = (4 - align) << 3;
		const UI1 shiftRight = align << 3;
		UI4 temp_value = 0;
		if (align <= 1)
			temp_value |= ui1_data[2] << 16;
		if (align <= 2)
			temp_value |= ui1_data[1] << 8;
		if (align <= 3)
			temp_value |= ui1_data[0];
		temp_value <<= align << 3;
		ui1_data += 4 - align;
		estimated -= 4 - align;
		while (estimated >= 4) {
			helder = MASTER_TOLE4(*(const UI4 *)ui1_data);
			temp_value = (temp_value >> shiftRight) | (helder << shiftLeft);
			MASTER_ALGOLIB_MURMURHASH2A_MIX(hash_value, temp_value);
			temp_value = helder;
			ui1_data += 4;
			estimated -= 4;
		}
		helder = 0;
		if (estimated >= align) {
			if (align >= 3)
				helder |= ui1_data[2] << 16;
			if (align >= 2)
				helder |= ui1_data[1] << 8;
			if (align >= 1)
				helder |= ui1_data[0];
			
			helder = (temp_value >> shiftRight) | (helder << shiftLeft);
			MASTER_ALGOLIB_MURMURHASH2A_MIX(hash_value, helder);
			
			ui1_data += align;
			estimated -= align;
			
			if (estimated >= 3)
				hash_value ^= ui1_data[2] << 16;
			if (estimated >= 2)
				hash_value ^= ui1_data[1] << 8;
			if (estimated >= 1) {
				hash_value ^= ui1_data[0];
				hash_value *= 0x5BD1E995;
			}
		} else {
			if (estimated >= 3)
				helder |= ui1_data[2] << 16;
			if (estimated >= 2)
				helder |= ui1_data[1] << 8;
			if (estimated >= 1)
				helder |= ui1_data[0];
			hash_value ^= (temp_value >> shiftRight) | (helder << shiftLeft);
			hash_value *= 0x5BD1E995;
		}
	} else {
		while (estimated >= 4) {
			helder = MASTER_TOLE4(*(const UI4 *)ui1_data);
			MASTER_ALGOLIB_MURMURHASH2A_MIX(hash_value, helder);
			ui1_data += 4;
			estimated -= 4;
		}
		if (estimated >= 3)
			hash_value ^= ui1_data[2] << 16;
		if (estimated >= 2)
			hash_value ^= ui1_data[1] << 8;
		if (estimated >= 1) {
			hash_value ^= ui1_data[0];
			hash_value *= 0x5BD1E995;
		}
	}
	hash_value ^= hash_value >> 13;
	hash_value *= 0x5BD1E995;
	hash_value ^= hash_value >> 15;
	return hash_value;
}

#define MASTER_ALGOLIB_MURMURHASH3_MIX32( hash_value ) do { \
		(hash_value) ^= (hash_value) >> 16; \
		(hash_value) *= 0x85EBCA6B; \
		(hash_value) ^= (hash_value) >> 13; \
		(hash_value) *= 0xC2B2AE35; \
		(hash_value) ^= (hash_value) >> 16; \
	} while (0)

#define MASTER_ALGOLIB_MURMURHASH3_MIX64( hash_value ) do { \
		(hash_value) ^= (hash_value) >> 33; \
		(hash_value) *= 0xFF51AFD7ED558CCD; \
		(hash_value) ^= (hash_value) >> 33; \
		(hash_value) *= 0xC4CEB9FE1A85EC53; \
		(hash_value) ^= (hash_value) >> 33; \
	} while (0)

/* #! TODO : FSM !# */
void
MASTER_Algolib_MurmurHash3x32o4( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint length, const UI4 seed_value, void * const MASTER_PREFER_RESTRICT output ) {
	UI4 hash_value = seed_value;
	UI4 helder;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul || output == nul) return;
	while (estimated >= 4) {
		helder = MASTER_TOLE4(*(const UI4 *)ui1_data);
		helder *= 0xCC9E2D51;
		helder = MASTER_RLL4(helder, 15);
		helder *= 0x1B873593;
		hash_value ^= helder;
		hash_value = MASTER_RLL4(hash_value, 13);
		hash_value = hash_value * 5 + 0xE6546B64;
		ui1_data += 4;
		estimated -= 4;
	}
	helder = 0;
	if (estimated >= 3)
		helder |= ui1_data[2] << 16;
	if (estimated >= 2)
		helder |= ui1_data[1] << 8;
	if (estimated >= 1) {
		helder |= ui1_data[0];
		helder *= 0xCC9E2D51;
		helder = MASTER_RLL4(helder, 15);
		helder *= 0x1B873593;
		hash_value ^= helder;
	}
	hash_value ^= length;
	MASTER_ALGOLIB_MURMURHASH3_MIX32(hash_value);
	*(UI4 *)output = hash_value;
}

/* #! TODO : FSM !# */
void
MASTER_Algolib_MurmurHash3x32o16( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint length, const UI4 seed_value, void * const MASTER_PREFER_RESTRICT output ) {
	UI4 hash_values[4];
	UI4 helders[4];
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul || output == nul) return;
	hash_values[0] = hash_values[1] = hash_values[2] = hash_values[3] = seed_value;
	while (estimated >= 16) {
		helders[0] = MASTER_TOLE4(*(const UI4 *)ui1_data);
		helders[1] = MASTER_TOLE4(*(const UI4 *)(ui1_data + 4));
		helders[2] = MASTER_TOLE4(*(const UI4 *)(ui1_data + 8));
		helders[3] = MASTER_TOLE4(*(const UI4 *)(ui1_data + 12));
		helders[0] *= 0x239B961B;
		helders[0] = MASTER_RLL4(helders[0], 15);
		helders[0] *= 0xAB0E9789;
		hash_values[0] ^= helders[0];
		hash_values[0] = MASTER_RLL4(hash_values[0], 19);
		hash_values[0] += hash_values[1];
		hash_values[0] = hash_values[0] * 5 + 0x561CCD1B;
		helders[1] *= 0xAB0E9789;
		helders[1] = MASTER_RLL4(helders[1], 16);
		helders[1] *= 0x38B34AE5;
		hash_values[1] ^= helders[1];
		hash_values[1] = MASTER_RLL4(hash_values[1], 17);
		hash_values[1] += hash_values[2];
		hash_values[1] = hash_values[1] * 5 + 0x0BCAA747;
		helders[2] *= 0x38B34AE5;
		helders[2] = MASTER_RLL4(helders[2], 17);
		helders[2] *= 0xA1E38B93;
		hash_values[2] ^= helders[2];
		hash_values[2] = MASTER_RLL4(hash_values[2], 15);
		hash_values[2] += hash_values[3];
		hash_values[2] = hash_values[2] * 5 + 0x96CD1C35;
		helders[3] *= 0xA1E38B93;
		helders[3] = MASTER_RLL4(helders[3], 18);
		helders[3] *= 0x239B961B;
		hash_values[3] ^= helders[3];
		hash_values[3] = MASTER_RLL4(hash_values[3], 13);
		hash_values[3] += hash_values[0];
		hash_values[3] = hash_values[3] * 5 + 0x32AC3B17;
		ui1_data += 16;
		estimated -= 16;
	}
	MASTER_MEMSET(helders, 0, 4 * sizeof(UI4));
	if (estimated >= 15)
		helders[3] |= ui1_data[14] << 16;
	if (estimated >= 14)
		helders[3] |= ui1_data[13] << 8;
	if (estimated >= 13) {
		helders[3] |= ui1_data[12];
		helders[3] *= 0xA1E38B93;
		helders[3] = MASTER_RLL4(helders[3], 18);
		helders[3] *= 0x239B961B;
		hash_values[3] ^= helders[3];
	}
	if (estimated >= 9) {
		if (estimated >= 12)
			helders[2] = MASTER_TOLE4(*(const UI4 *)(ui1_data + 8));
		else {
			if (estimated >= 11)
				helders[2] |= ui1_data[10] << 16;
			if (estimated >= 10)
				helders[2] |= ui1_data[9] << 8;
			helders[2] |= ui1_data[8];
		}
		helders[2] *= 0x38B34AE5;
		helders[2] = MASTER_RLL4(helders[2], 17);
		helders[2] *= 0xA1E38B93;
		hash_values[2] ^= helders[2];
	}
	if (estimated >= 5) {
		if (estimated >= 8)
			helders[1] = MASTER_TOLE4(*(const UI4 *)(ui1_data + 4));
		else {
			if (estimated >= 7)
				helders[1] |= ui1_data[6] << 16;
			if (estimated >= 6)
				helders[1] |= ui1_data[5] << 8;
			helders[1] |= ui1_data[4];
		}
		helders[1] *= 0xAB0E9789;
		helders[1] = MASTER_RLL4(helders[1], 16);
		helders[1] *= 0x38B34AE5;
		hash_values[1] ^= helders[1];
	}
	if (estimated >= 1) {
		if (estimated >= 4)
			helders[0] = MASTER_TOLE4(*(const UI4 *)ui1_data);
		else {
			if (estimated >= 3)
				helders[0] |= ui1_data[2] << 16;
			if (estimated >= 2)
				helders[0] |= ui1_data[1] << 8;
			helders[0] |= ui1_data[0];
		}
		helders[0] *= 0x239B961B;
		helders[0] = MASTER_RLL4(helders[0], 15);
		helders[0] *= 0xAB0E9789;
		hash_values[0] ^= helders[0];
	}
	hash_values[0] ^= length;
	hash_values[1] ^= length;
	hash_values[2] ^= length;
	hash_values[3] ^= length;
	hash_values[0] += hash_values[1] + hash_values[2] + hash_values[3];
	hash_values[1] += hash_values[0];
	hash_values[2] += hash_values[0];
	hash_values[3] += hash_values[0];
	MASTER_ALGOLIB_MURMURHASH3_MIX32(hash_values[0]);
	MASTER_ALGOLIB_MURMURHASH3_MIX32(hash_values[1]);
	MASTER_ALGOLIB_MURMURHASH3_MIX32(hash_values[2]);
	MASTER_ALGOLIB_MURMURHASH3_MIX32(hash_values[3]);
	hash_values[0] += hash_values[1] + hash_values[2] + hash_values[3];
	hash_values[1] += hash_values[0];
	hash_values[2] += hash_values[0];
	hash_values[3] += hash_values[0];
	((UI4 *)output)[0] = hash_values[0];
	((UI4 *)output)[1] = hash_values[1];
	((UI4 *)output)[2] = hash_values[2];
	((UI4 *)output)[3] = hash_values[3];
}

#if MASTER_64_AVAILABLE == 1
/* #! TODO : FSM !# */
void
MASTER_Algolib_MurmurHash3x64o16( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint length, const UI4 seed_value, void * const MASTER_PREFER_RESTRICT output ) {
	UI8 hash_values[2];
	UI8 helders[2];
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul || output == nul) return;
	hash_values[0] = hash_values[1] = seed_value;
	while (estimated >= 16) {
		helders[0] = MASTER_TOLE8(*(const UI8 *)ui1_data);
		helders[1] = MASTER_TOLE8(*(const UI8 *)(ui1_data + 8));
		helders[0] *= 0x87C37B91114253D5;
		helders[0] = MASTER_RLL8(helders[0], 31);
		helders[0] *= 0x4CF5AD432745937F;
		hash_values[0] ^= helders[0];
		hash_values[0] = MASTER_RLL8(hash_values[0], 27);
		hash_values[0] += hash_values[1];
		hash_values[0] = hash_values[0] * 5 + 0x52DCE729;
		helders[1] *= 0x4CF5AD432745937F;
		helders[1] = MASTER_RLL8(helders[1], 33);
		helders[1] *= 0x87C37B91114253D5;
		hash_values[1] ^= helders[1];
		hash_values[1] = MASTER_RLL8(hash_values[1], 31);
		hash_values[1] += hash_values[0];
		hash_values[1] = hash_values[1] * 5 + 0x38495AB5;
		ui1_data += 16;
		estimated -= 16;
	}
	MASTER_MEMSET(helders, 0, 2 * sizeof(UI8));
	if (estimated >= 15)
		helders[1] |= (UI8)ui1_data[14] << 48;
	if (estimated >= 14)
		helders[1] |= (UI8)ui1_data[13] << 40;
	if (estimated >= 13)
		helders[1] |= (UI8)ui1_data[12] << 32;
	if (estimated >= 12)
		helders[1] |= (UI8)ui1_data[11] << 24;
	if (estimated >= 11)
		helders[1] |= (UI8)ui1_data[10] << 16;
	if (estimated >= 10)
		helders[1] |= (UI8)ui1_data[9] << 8;
	if (estimated >= 9) {
		helders[1] |= (UI8)ui1_data[8];
		helders[1] *= 0x4CF5AD432745937F;
		helders[1] = MASTER_RLL8(helders[1], 33);
		helders[1] *= 0x87C37B91114253D5;
		hash_values[1] ^= helders[1];
	}
	if (estimated >= 1) {
		if (estimated >= 8)
			helders[0] = MASTER_TOLE8(*(const UI8 *)ui1_data);
		else {
			if (estimated >= 7)
				helders[0] |= (UI8)ui1_data[6] << 48;
			if (estimated >= 6)
				helders[0] |= (UI8)ui1_data[5] << 40;
			if (estimated >= 5)
				helders[0] |= (UI8)ui1_data[4] << 32;
			if (estimated >= 4)
				helders[0] |= (UI8)ui1_data[3] << 24;
			if (estimated >= 3)
				helders[0] |= (UI8)ui1_data[2] << 16;
			if (estimated >= 2)
				helders[0] |= (UI8)ui1_data[1] << 8;
			helders[0] |= (UI8)ui1_data[0];
		}
		helders[0] *= 0x87C37B91114253D5;
		helders[0] = MASTER_RLL8(helders[0], 31);
		helders[0] *= 0x4CF5AD432745937F;
		hash_values[0] ^= helders[0];
	}
	hash_values[0] ^= (UI4)length;
	hash_values[1] ^= (UI4)length;
	hash_values[0] += hash_values[1];
	hash_values[1] += hash_values[0];
	MASTER_ALGOLIB_MURMURHASH3_MIX64(hash_values[0]);
	MASTER_ALGOLIB_MURMURHASH3_MIX64(hash_values[1]);
	hash_values[0] += hash_values[1];
	hash_values[1] += hash_values[0];
	((UI8 *)output)[0] = hash_values[0];
	((UI8 *)output)[1] = hash_values[1];
}
#endif /* #! 64 Bits !# */

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

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Algolib_Cell *, MASTER_Algolib_Cell_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DancingLinks_Init, ( MASTER_Algolib_DancingLinks * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Algolib_DancingLinks, MASTER_Algolib_DancingLinks_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DancingLinks_AddRow, ( MASTER_Algolib_DancingLinks * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DancingLinks_AddColumn, ( MASTER_Algolib_DancingLinks * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_Cell_FreeRow, ( MASTER_Algolib_Cell * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DancingLinks_Free, ( MASTER_Algolib_DancingLinks * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DancingLinks_Set, ( MASTER_Algolib_DancingLinks * const, const UI4, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Algolib_Cell *, MASTER_Algolib_DancingLinks_PickColumn, ( MASTER_Algolib_DancingLinks * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DancingLinks_Cover, ( MASTER_Algolib_Cell * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DancingLinks_Uncover, ( MASTER_Algolib_Cell * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DancingLinks_Solve, ( MASTER_Algolib_DancingLinks * const, const MASTER_Algolib_DancingLinks_FoundType, const MASTER_Algolib_DancingLinks_StuckedType, const MASTER_Algolib_DancingLinks_TryingType, const MASTER_Algolib_DancingLinks_UndoType ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_DancingLinks_MakeOptional, ( MASTER_Algolib_DancingLinks * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_DancingLinks_PickRow, ( MASTER_Algolib_DancingLinks * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_DancingLinks_RemoveRow, ( MASTER_Algolib_DancingLinks * const, const UI4 ) );

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


MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zRIVATE_ALGOLIB_INCLUDE_H_LAST_LINE = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zRIVATE_ALGOLIB_INCLUDE_H !# */

/* #! be master !# */
