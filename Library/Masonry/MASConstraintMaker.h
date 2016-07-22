//
//  MASConstraintBuilder.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "MASConstraint.h"
#import "MASUtilities.h"

/**
 *  Provides factory methods for creating MASConstraints.
 *  Constraints are collected until they are ready to be installed
 *
 */
@interface MASConstraintMaker : NSObject

/**
 *	The following properties return a new MASViewConstraint
 *  with the first item set to the makers associated view and the appropriate MASViewAttribute
 */
@property (nonatomic, strong, readonly) MASConstraint *left;
@property (nonatomic, strong, readonly) MASConstraint *top;
@property (nonatomic, strong, readonly) MASConstraint *right;
@property (nonatomic, strong, readonly) MASConstraint *bottom;
@property (nonatomic, strong, readonly) MASConstraint *leading;
@property (nonatomic, strong, readonly) MASConstraint *trailing;
@property (nonatomic, strong, readonly) MASConstraint *width;
@property (nonatomic, strong, readonly) MASConstraint *height;
@property (nonatomic, strong, readonly) MASConstraint *centerX;
@property (nonatomic, strong, readonly) MASConstraint *centerY;
@property (nonatomic, strong, readonly) MASConstraint *baseline;

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeEdges
 *  which generates the appropriate MASViewConstraint children (top, left, bottom, right)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) MASConstraint *edges;

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeSize
 *  which generates the appropriate MASViewConstraint children (width, height)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) MASConstraint *size;

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeCenter
 *  which generates the appropriate MASViewConstraint children (centerX, centerY)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) MASConstraint *center;

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *	initialises the maker with a default view
 *
 *	@param	view	any MASConstrait are created with this view as the first item
 *
 *	@return	a new MASConstraintMaker
 */
- (id)initWithView:(MAS_VIEW *)view;

/**
 *	Calls install method on any MASConstraints which have been created by this maker
 *
 *	@return	an array of all the installed MASConstraints
 */
- (NSArray *)install;

- (MASConstraint * (^)(dispatch_block_t))group;

@end
