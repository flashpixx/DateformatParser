grammar Dateformat;


/**
 * Startregel
 */
main :
    dateelement+
    ;

/**
 * Regel für ein einzelnes Datumselements
 */
dateelement :
    dateunit now? sign? number?
    ;

/**
 * Regel für ein Datumseinheit
 */
dateunit :
    DAY
    | WEEK
    | MONTH
    | QUARTER
    | HALFYEAR
    | YEAR
    ;

/**
 * Vorzeichen für Number
 */
sign :
    PLUS
    | MINUS
    ;

/**
 * Regel für Zahlen (Integer)
 */
number :
    DIGIT+
    ;

/**
 * Regel für now
 */
now :
    NOW
    ;

// --- Terminale -----------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Terminal für Plus
 */
PLUS        : '+';

/**
 * Terminal für Minus
 */
MINUS       : '-';


/**
 * Terminal für Tage
 */
DAY         : 'd' | 't';

/**
 * Terminal für Wochen
 */
WEEK        : 'w';

/**
 * Terminal für Monate
 */
MONTH       : 'm';

/**
 * Terminal für Vierteljahre
 */
QUARTER     : 'q';

/**
 * Terminal für Halbjahre
 */
HALFYEAR    : 'h';

/**
 * Terminal für Jahre
 */
YEAR        : 'j' | 'y';

/**
 * Terminal für 'jetzt'
 */
NOW         : '#' | 'now' | 'jetzt';

/**
 * Terminal für Zahlen
 */
DIGIT       : [0-9];

/**
 * Terminal Leerzeichen (ignorieren)
 **/
WHITESPACE  : (' ' | '\n' | '\t' | '\r')+ -> skip;