
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
#include <bitlib.h>

MASTER_BEGIN_DECLARATIONS

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_CheckBrackets, ( const char * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_IsPrime, ( const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_CalculateSpan, ( const UI4 * const, UI4 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_maxint, MASTER_Algolib_DJB2, ( const UI1 *, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_maxint, MASTER_Algolib_SDBM, ( const UI1 *, MASTER_maxint ) );
typedef struct MASTER_Algolib_TreeNode MASTER_Algolib_TreeNode;
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
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_MaximumProduct, ( MASTER_Algolib_TreeNode * ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_SumOfFourDivisors, ( const UI4 *, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_NumberOfWaysToPaintN3Grid, ( const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_MaximumDotProduct, ( const SI4 * const, const UI4, const SI4 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_TotalMoney, ( const SI4 value ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_MinimumXorSum, ( const UI4 *, const UI4 *, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_MaximumMatrixSum, ( const SI4 * const * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_signed_maxint, MASTER_Algolib_CountQuadruplets, ( const SI4 *, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4**, MASTER_Algolib_MergeArrays, ( const SI4**, const UI4, const SI4**, const UI4, SI4 *, SI4** ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_KnightMaximumMoves, ( const SI4, const SI4, const SI4** const, const UI4 ) );

struct MASTER_Algolib_TreeNode {
	SI4 val;
	struct MASTER_Algolib_TreeNode * left;
	struct MASTER_Algolib_TreeNode * right;
};

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
	array[array_pointer] = root->val;
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
	SI4 maxSum = root->val;
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
			curSum += node->val;
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

MASTER_PREFER_STATIC SI4
maxProduct_DFS( MASTER_Algolib_TreeNode * root, SI4 * const subTreeSums, UI4 * const index ) {
	SI4 totalSum = root->val;
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
	const UI4 __MASTER_ALGOLIB_INCLUDE_H_LAST_LINE__ = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! __MASTER_ALGOLIB_INCLUDE_H__ !# */

/* #! be master !# */
