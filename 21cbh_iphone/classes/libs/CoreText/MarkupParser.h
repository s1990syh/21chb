//
//  MarkupParser.h
//  CoreTextDemo
//
//  Created by 海军 高 on 11-12-23.
//  Copyright (c) 2011年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>
@interface MarkupParser : NSObject
{
    NSString *font;
    UIColor *color;
    UIColor *strokeColor;
    float stokeWidth;
}

@property (retain, nonatomic) NSString* font;
@property (retain, nonatomic) UIColor* color;
@property (retain, nonatomic) UIColor* strokeColor;
@property (assign, readwrite) float strokeWidth;

- (NSMutableAttributedString *)attrStringFromMarkup:(NSString*)markup images:(NSMutableArray *)images;

@end
