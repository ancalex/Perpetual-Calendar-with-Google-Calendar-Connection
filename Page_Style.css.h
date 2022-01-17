#ifndef PAGE_STYLE_CSS_H
#define PAGE_STYLE_CSS_H

const char PAGE_Style_css[] PROGMEM = R"=====(
hr {
    background-color: #eee;
    border: 0 none;
    color: #eee;
    height: 1px;
}
.btn, .btn:link, .btn:visited {
    border-radius: 0.3em;
    border-style: solid;
    border-width: 1px;
    color: #111;
    display: inline-block;
    font-family: avenir, helvetica, arial, sans-serif;
    letter-spacing: 0.15em;
    margin-bottom: 0.5em;
    padding: 1em 0.75em;
    text-decoration: none;
    text-transform: uppercase;
    -webkit-transition: color 0.4s, background-color 0.4s, border 0.4s;
    transition: color 0.4s, background-color 0.4s, border 0.4s;
}
.btn:hover, .btn:focus {
    color: #DFE0E2;
    border: 1px solid #DFE0E2;
    -webkit-transition: background-color 0.3s, color 0.3s, border 0.3s;
    transition: background-color 0.3s, color 0.3s, border 0.3s;
}
.btn:active {
    color: #646162;
    border: 1px solid #646162;
    -webkit-transition: background-color 0.3s, color 0.3s, border 0.3s;
    transition: background-color 0.3s, color 0.3s, border 0.3s;
}
.btn--s{
    font-size: 12px;
}
.btn--m {
    font-size: 14px;
}
.btn--l {
    font-size: 20px;
    border-radius: 0.25em !important;
}
.btn--full, .btn--full:link {
    border-radius: 0.25em;
    display: block;
    margin-left: auto;
    margin-right: auto;
    text-align: center;
    width: 100%;
}
.btn--grey:link, .btn--grey:visited {
    color: #fff;
    background-color: #646162;
}
.btn--grey:hover, .btn--grey:focus {
    color: #fff !important;
    background-color: #B9BAB4;
    border-color: #B9BAB4;
}
.btn--grey:active {
    color: #fff;
    background-color: #A7A88A;
    border-color: #A7A88A;
}
@media screen and (min-width: 32em) {
    .btn--full {
        max-width: 16em !important;
    }
}
)=====";

#endif
