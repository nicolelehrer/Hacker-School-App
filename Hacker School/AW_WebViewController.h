//
//  AW_WebViewController.h
//  Hacker School
//
//  Created by Alan Wang on 2/4/15.
//  Copyright (c) 2015 Alan Wang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@class AW_MainViewController;

/**
    A general purpose view controller, which displays a WKWebView loaded with the provided URL. It includes a progress bar, and a Back button
    (on the right side of the navigation bar). It injects JavaScript before the page loads, using the hideStuff.js file in order to hide
    certain elements of the loaded webpage (i.e. the Hacker School navigation bar, so that you cannot navigate to other parts of the site from
    within the web view). Hyperlinks within recurse.com are opened in the web view. Hyperlinks that go outside of recurse.com are
    redirected to Mobile Safari.

    @brief A general purpose view controller, which simply displays a WKWebView loaded with the provided URL.
 */
@interface AW_WebViewController : UIViewController

@property (nonatomic, weak) AW_MainViewController *mainVC;  ///< A weak reference to the AW_MainViewController in order to call its public methods.
@property (nonatomic, strong) NSString *navBarTitle;        ///< The string to display in the navigation bar.
@property (nonatomic, strong) NSURL *url;                   ///< The initial URL to load the web view to.
@property (nonatomic, strong) WKProcessPool *processPool;   ///< Process pool to use for webview. Set this before the view is loaded.

/**
    Override this method in subclasses to provide different configurations to the webview
 */
- (WKWebViewConfiguration *)webViewConfiguration;

@end
