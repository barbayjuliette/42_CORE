<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * Localized language
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'juliette_database' );

/** Database username */
define( 'DB_USER', 'your_wordpress_database_user' );

/** Database password */
define( 'DB_PASSWORD', 'your_wordpress_database_password' );

/** Database hostname */
define( 'DB_HOST', 'mariadb:3306' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',          'Ah)=Gd&$v7XiSRb`1usCr;#8!d8@0$%;>8krq#X9VNL05{07`e7S/FKUBHt^qmrE' );
define( 'SECURE_AUTH_KEY',   'lk*2S`_5{Q#] -kM#//dhk$gC+qNHR-z/A0SUvkYBpc%@X)ag4cL#c8NPpleS`Ow' );
define( 'LOGGED_IN_KEY',     '$1U?Snt2hN~L~|*Ii(YMGu)(|hoSkTBOSe>F~ErTwKZ%2AA6p&_LRe_:.Nw1|Q75' );
define( 'NONCE_KEY',         'kH96Bf{(Rwx(#hvP4=f2o>N/W/pd3x`,snJkn*/9O!iuzW0u>i)RhAiNFU (T5 E' );
define( 'AUTH_SALT',         '.>dsAkhc/Ar]rohow0[3|Nc:B1zZQ?8rWR-qVPyE-<4gC^<ANqTItICU)@o5Ju{G' );
define( 'SECURE_AUTH_SALT',  '=lO9xSg<q4f7E7$/=,9+H[(0=*H-4A>|!G,UUY.3Z,oI|t6&y<x?}}NR(N?G;tL(' );
define( 'LOGGED_IN_SALT',    's2O![MB}Ci#NW+He!.%?I-=I@t$_xrjL:bD0})SsUAQg:vR8IT]:C:^{_y4}%?Rk' );
define( 'NONCE_SALT',        'xRA[nITEP>f(S&#ye+&SMVD&CE_1CP]cZHKfa?*yS**u9B[=5&8Y+uB:(J.0 ))g' );
define( 'WP_CACHE_KEY_SALT', 'U3lUp~DNyXC!M#7.s=(m0MxS6W,pQKsQ_2tj?^m$vnwg`}|qJoWe{j Gi5j -Qtx' );


/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';


/* Add any custom values between this line and the "stop editing" line. */



/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
if ( ! defined( 'WP_DEBUG' ) ) {
	define( 'WP_DEBUG', false );
}

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
