/*!
 @header Frontia.h
 @abstract Frontia框架的入口类。开发者通过该类获取插件的实例。
 @version 1.00 2013/06/06 Creation
 @copyright (c) 2013 baidu. All rights reserved.
 */
#import <Foundation/Foundation.h> 
#import <UIKit/UIKit.h>

#import "FrontiaAuthorization.h"
#import "FrontiaPersonalStorage.h"
#import "FrontiaStorage.h"
#import "FrontiaPush.h"
#import "FrontiaAccount.h"
#import "FrontiaStatistics.h"
#import "IModule.h"
#import "FrontiaShare.h"
#import "FrontiaLBS.h"

/*!
 @class
 @abstract Frontia框架的入口类。开发者通过该类获取插件的实例。
 @discussion 在使用的时候需要先进行初始化，可以调用下边函数来进行初始化，传入Context与在百度开发者中心申请的应用的API Key。
     
       [Frontia initWithApiKey:apiKey];
 
 在初始化以后，可以调用获取某一个服务，比如可以调用下边的代码来获取存储服务。在获取服务以后可以进行相应的操作，比如存储等。
 
       FrontiaStorage *storage = [Frontia getStorage];
 
 在访问一些服务的时候，需要进行ACL认证，可以下边接口来设置当前用户。
       
       [Frontia setCurrentAccount:account];
 */
@interface Frontia : NSObject

@property (nonatomic, strong) NSString* verifyAK;

/*!
 @method
 @abstract Frontia入口类的初始化函数。
 @param ApiKey 应用的ApiKey
 @result 如果初始化成功，返回TRUE；否则返回FALSE。
 */
+(BOOL)initWithApiKey:(NSString*)ApiKey;

/*!
 @method
 @abstract 获取初始化Frontia的app Key。
 @result
 app Key。
 */
+(NSString*)getApiKey;

/*!
 @method
 @abstract 获取当前用户信息。
 @discussion 
    如果没有设置或者当前用户信息被清除，此方法返回空对象
 @result
    当前用户对象的实例。
 */
+(FrontiaAccount*)currentAccount;

/*!
 @method
 @abstract 设置当前用户。
 @param user 当前用户。可以是包含social_id的FrontiaUser实例或者是包含role_id的FrontiaRole实例
 */
+(void)setCurrentAccount:(FrontiaAccount*)user;

/*!
@method 动态加载模块
@abstract 通过模块名称动态加载插件。
@param moduleName 需要动态加载的插件名。
@result 指定加载的模块对象。
*/
+(id<IModule>)getModule:(NSString*)moduleName;

/*!
 @method
 @abstract 加载Authorization插件。
 @result 
 Authorization插件的实例。
 */
+(FrontiaAuthorization*)getAuthorization;

/*!
 @method
 @abstract 加载PersonalStorage插件。
 @result
 PersonalStorage插件的实例。
 */
+(FrontiaPersonalStorage*)getPersonalStorage;

/*!
 @method
 @abstract 加载Push插件。
 @result
 Push插件的实例。
 */
+(FrontiaPush*)getPush;

/*!
 @method
 @abstract 加载Storage模块。
 @Storage
 Push模块的实例。
 */
+(FrontiaStorage*)getStorage;

/*!
 @method
 @abstract 加载Statistics模块。
 @return 统计模块的实例。
 */
+(FrontiaStatistics*)getStatistics;

/*!
 @method
 @abstract 加载DeepLink模块。
 @return DeepLink的实例。
+(FrontiaDeepLink*)getDeepLink; */


/*!
 @method
 @abstract 加载Share模块。
 @return Share的实例。
 */
+(FrontiaShare*)getShare;

/*!
 @method
 @abstract 加载LBS模块。
 @return LBS的实例。
 */
+(FrontiaLBS*)getLBS;

@end
