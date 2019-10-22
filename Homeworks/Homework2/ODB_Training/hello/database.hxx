<!DOCTYPE html>
<html lang='en'>
<head>
<title>database.hxx\hello - odb-examples - ODB examples
</title>
<meta name='generator' content='cgit v1.1'/>
<meta name='robots' content='noindex, nofollow'/>
<link rel='stylesheet' type='text/css' href='/cgit-css/cgit.css'/>
<link rel='shortcut icon' href='/favicon.ico'/>
<link rel='alternate' title='Atom feed' href='https://git.codesynthesis.com/cgit/odb/odb-examples/atom/hello/database.hxx?h=master' type='application/atom+xml'/>
<link rel='vcs-git' href='git://git.codesynthesis.com/odb/odb-examples.git' title='odb-examples Git repository'/>
<link rel='vcs-git' href='https://git.codesynthesis.com/odb/odb-examples.git' title='odb-examples Git repository'/>
</head>
<body>
<div id='cgit'><table id='header'>
<tr>
<td class='logo' rowspan='2'><a href='https://git.codesynthesis.com/'><img src='/cgit-css/cgit.png' alt='cgit logo'/></a></td>
<td class='main'><a href='/cgit/'>index</a> : <a title='odb-examples' href='/cgit/odb/odb-examples/'>odb-examples</a></td><td class='form'><form method='get'>
<select name='h' onchange='this.form.submit();'>
<option value='1.6'>1.6</option>
<option value='2.1'>2.1</option>
<option value='2.3'>2.3</option>
<option value='as'>as</option>
<option value='bulk'>bulk</option>
<option value='master' selected='selected'>master</option>
</select> <input type='submit' value='switch'/></form></td></tr>
<tr><td class='sub'>ODB examples
</td><td class='sub right'>Boris Kolpackov</td></tr></table>
<table class='tabs'><tr><td>
<a href='/cgit/odb/odb-examples/about/'>about</a><a href='/cgit/odb/odb-examples/'>summary</a><a href='/cgit/odb/odb-examples/refs/'>refs</a><a href='/cgit/odb/odb-examples/log/hello/database.hxx'>log</a><a class='active' href='/cgit/odb/odb-examples/tree/hello/database.hxx'>tree</a><a href='/cgit/odb/odb-examples/commit/hello/database.hxx'>commit</a><a href='/cgit/odb/odb-examples/diff/hello/database.hxx'>diff</a></td><td class='form'><form class='right' method='get' action='/cgit/odb/odb-examples/log/hello/database.hxx'>
<select name='qt'>
<option value='grep'>log msg</option>
<option value='author'>author</option>
<option value='committer'>committer</option>
<option value='range'>range</option>
</select>
<input class='txt' type='text' size='10' name='q' value=''/>
<input type='submit' value='search'/>
</form>
</td></tr></table>
<div class='path'>path: <a href='/cgit/odb/odb-examples/tree/'>root</a>/<a href='/cgit/odb/odb-examples/tree/hello'>hello</a>/<a href='/cgit/odb/odb-examples/tree/hello/database.hxx'>database.hxx</a></div><div class='content'>blob: 283f5cb3397a52562033d9296b75a7e7604b2b4b (<a href='/cgit/odb/odb-examples/plain/hello/database.hxx'>plain</a>)
<table summary='blob content' class='blob'>
<tr><td class='linenumbers'><pre><a id='n1' href='#n1'>1</a>
<a id='n2' href='#n2'>2</a>
<a id='n3' href='#n3'>3</a>
<a id='n4' href='#n4'>4</a>
<a id='n5' href='#n5'>5</a>
<a id='n6' href='#n6'>6</a>
<a id='n7' href='#n7'>7</a>
<a id='n8' href='#n8'>8</a>
<a id='n9' href='#n9'>9</a>
<a id='n10' href='#n10'>10</a>
<a id='n11' href='#n11'>11</a>
<a id='n12' href='#n12'>12</a>
<a id='n13' href='#n13'>13</a>
<a id='n14' href='#n14'>14</a>
<a id='n15' href='#n15'>15</a>
<a id='n16' href='#n16'>16</a>
<a id='n17' href='#n17'>17</a>
<a id='n18' href='#n18'>18</a>
<a id='n19' href='#n19'>19</a>
<a id='n20' href='#n20'>20</a>
<a id='n21' href='#n21'>21</a>
<a id='n22' href='#n22'>22</a>
<a id='n23' href='#n23'>23</a>
<a id='n24' href='#n24'>24</a>
<a id='n25' href='#n25'>25</a>
<a id='n26' href='#n26'>26</a>
<a id='n27' href='#n27'>27</a>
<a id='n28' href='#n28'>28</a>
<a id='n29' href='#n29'>29</a>
<a id='n30' href='#n30'>30</a>
<a id='n31' href='#n31'>31</a>
<a id='n32' href='#n32'>32</a>
<a id='n33' href='#n33'>33</a>
<a id='n34' href='#n34'>34</a>
<a id='n35' href='#n35'>35</a>
<a id='n36' href='#n36'>36</a>
<a id='n37' href='#n37'>37</a>
<a id='n38' href='#n38'>38</a>
<a id='n39' href='#n39'>39</a>
<a id='n40' href='#n40'>40</a>
<a id='n41' href='#n41'>41</a>
<a id='n42' href='#n42'>42</a>
<a id='n43' href='#n43'>43</a>
<a id='n44' href='#n44'>44</a>
<a id='n45' href='#n45'>45</a>
<a id='n46' href='#n46'>46</a>
<a id='n47' href='#n47'>47</a>
<a id='n48' href='#n48'>48</a>
<a id='n49' href='#n49'>49</a>
<a id='n50' href='#n50'>50</a>
<a id='n51' href='#n51'>51</a>
<a id='n52' href='#n52'>52</a>
<a id='n53' href='#n53'>53</a>
<a id='n54' href='#n54'>54</a>
<a id='n55' href='#n55'>55</a>
<a id='n56' href='#n56'>56</a>
<a id='n57' href='#n57'>57</a>
<a id='n58' href='#n58'>58</a>
<a id='n59' href='#n59'>59</a>
<a id='n60' href='#n60'>60</a>
<a id='n61' href='#n61'>61</a>
<a id='n62' href='#n62'>62</a>
<a id='n63' href='#n63'>63</a>
<a id='n64' href='#n64'>64</a>
<a id='n65' href='#n65'>65</a>
<a id='n66' href='#n66'>66</a>
<a id='n67' href='#n67'>67</a>
<a id='n68' href='#n68'>68</a>
<a id='n69' href='#n69'>69</a>
<a id='n70' href='#n70'>70</a>
<a id='n71' href='#n71'>71</a>
<a id='n72' href='#n72'>72</a>
<a id='n73' href='#n73'>73</a>
<a id='n74' href='#n74'>74</a>
<a id='n75' href='#n75'>75</a>
<a id='n76' href='#n76'>76</a>
<a id='n77' href='#n77'>77</a>
<a id='n78' href='#n78'>78</a>
<a id='n79' href='#n79'>79</a>
<a id='n80' href='#n80'>80</a>
<a id='n81' href='#n81'>81</a>
<a id='n82' href='#n82'>82</a>
<a id='n83' href='#n83'>83</a>
<a id='n84' href='#n84'>84</a>
<a id='n85' href='#n85'>85</a>
<a id='n86' href='#n86'>86</a>
<a id='n87' href='#n87'>87</a>
<a id='n88' href='#n88'>88</a>
<a id='n89' href='#n89'>89</a>
<a id='n90' href='#n90'>90</a>
<a id='n91' href='#n91'>91</a>
<a id='n92' href='#n92'>92</a>
<a id='n93' href='#n93'>93</a>
<a id='n94' href='#n94'>94</a>
</pre></td>
<td class='lines'><pre><code><span style="color:#838183; font-style:italic">// file      : hello/database.hxx</span>
<span style="color:#838183; font-style:italic">// copyright : not copyrighted - public domain</span>

<span style="color:#838183; font-style:italic">//</span>
<span style="color:#838183; font-style:italic">// Create concrete database instance based on the DATABASE_* macros.</span>
<span style="color:#838183; font-style:italic">//</span>

<span style="color:#008200">#ifndef DATABASE_HXX</span>
<span style="color:#008200">#define DATABASE_HXX</span>

<span style="color:#008200">#include &lt;string&gt;</span>
<span style="color:#008200">#include &lt;memory&gt;</span>   <span style="color:#838183; font-style:italic">// std::auto_ptr</span>
<span style="color:#008200"></span><span style="color:#008200">#include &lt;cstdlib&gt;</span>  <span style="color:#838183; font-style:italic">// std::exit</span>
<span style="color:#008200"></span><span style="color:#008200">#include &lt;iostream&gt;</span>

<span style="color:#008200">#include &lt;odb/database.hxx&gt;</span>

<span style="color:#008200">#if defined(DATABASE_MYSQL)</span>
<span style="color:#008200">#  include &lt;odb/mysql/database.hxx&gt;</span>
<span style="color:#008200">#elif defined(DATABASE_SQLITE)</span>
<span style="color:#008200">#  include &lt;odb/connection.hxx&gt;</span>
<span style="color:#008200">#  include &lt;odb/transaction.hxx&gt;</span>
<span style="color:#008200">#  include &lt;odb/schema-catalog.hxx&gt;</span>
<span style="color:#008200">#  include &lt;odb/sqlite/database.hxx&gt;</span>
<span style="color:#008200">#elif defined(DATABASE_PGSQL)</span>
<span style="color:#008200">#  include &lt;odb/pgsql/database.hxx&gt;</span>
<span style="color:#008200">#elif defined(DATABASE_ORACLE)</span>
<span style="color:#008200">#  include &lt;odb/oracle/database.hxx&gt;</span>
<span style="color:#008200">#elif defined(DATABASE_MSSQL)</span>
<span style="color:#008200">#  include &lt;odb/mssql/database.hxx&gt;</span>
<span style="color:#008200">#else</span>
<span style="color:#008200">#  error unknown database; did you forget to define the DATABASE_* macros?</span>
<span style="color:#008200">#endif</span>

<span style="color:#000000; font-weight:bold">inline</span> std<span style="color:#000000">::</span>auto_ptr<span style="color:#000000">&lt;</span>odb<span style="color:#000000">::</span>database<span style="color:#000000">&gt;</span>
<span style="color:#010181">create_database</span> <span style="color:#000000">(</span><span style="color:#0057ae">int</span><span style="color:#000000">&amp;</span> argc<span style="color:#000000">,</span> <span style="color:#0057ae">char</span><span style="color:#000000">*</span> argv<span style="color:#000000">[])</span>
<span style="color:#000000">{</span>
  <span style="color:#000000; font-weight:bold">using namespace</span> std<span style="color:#000000">;</span>
  <span style="color:#000000; font-weight:bold">using namespace</span> odb<span style="color:#000000">::</span>core<span style="color:#000000">;</span>

  <span style="color:#000000; font-weight:bold">if</span> <span style="color:#000000">(</span>argc <span style="color:#000000">&gt;</span> <span style="color:#b07e00">1</span> <span style="color:#000000">&amp;&amp;</span> argv<span style="color:#000000">[</span><span style="color:#b07e00">1</span><span style="color:#000000">] ==</span> <span style="color:#010181">string</span> <span style="color:#000000">(</span><span style="color:#bf0303">&quot;--help&quot;</span><span style="color:#000000">))</span>
  <span style="color:#000000">{</span>
    cout <span style="color:#000000">&lt;&lt;</span> <span style="color:#bf0303">&quot;Usage: &quot;</span> <span style="color:#000000">&lt;&lt;</span> argv<span style="color:#000000">[</span><span style="color:#b07e00">0</span><span style="color:#000000">] &lt;&lt;</span> <span style="color:#bf0303">&quot; [options]&quot;</span> <span style="color:#000000">&lt;&lt;</span> endl
         <span style="color:#000000">&lt;&lt;</span> <span style="color:#bf0303">&quot;Options:&quot;</span> <span style="color:#000000">&lt;&lt;</span> endl<span style="color:#000000">;</span>

<span style="color:#008200">#if defined(DATABASE_MYSQL)</span>
    odb<span style="color:#000000">::</span>mysql<span style="color:#000000">::</span>database<span style="color:#000000">::</span><span style="color:#010181">print_usage</span> <span style="color:#000000">(</span>cout<span style="color:#000000">);</span>
<span style="color:#008200">#elif defined(DATABASE_SQLITE)</span>
    odb<span style="color:#000000">::</span>sqlite<span style="color:#000000">::</span>database<span style="color:#000000">::</span><span style="color:#010181">print_usage</span> <span style="color:#000000">(</span>cout<span style="color:#000000">);</span>
<span style="color:#008200">#elif defined(DATABASE_PGSQL)</span>
    odb<span style="color:#000000">::</span>pgsql<span style="color:#000000">::</span>database<span style="color:#000000">::</span><span style="color:#010181">print_usage</span> <span style="color:#000000">(</span>cout<span style="color:#000000">);</span>
<span style="color:#008200">#elif defined(DATABASE_ORACLE)</span>
    odb<span style="color:#000000">::</span>oracle<span style="color:#000000">::</span>database<span style="color:#000000">::</span><span style="color:#010181">print_usage</span> <span style="color:#000000">(</span>cout<span style="color:#000000">);</span>
<span style="color:#008200">#elif defined(DATABASE_MSSQL)</span>
    odb<span style="color:#000000">::</span>mssql<span style="color:#000000">::</span>database<span style="color:#000000">::</span><span style="color:#010181">print_usage</span> <span style="color:#000000">(</span>cout<span style="color:#000000">);</span>
<span style="color:#008200">#endif</span>

    <span style="color:#010181">exit</span> <span style="color:#000000">(</span><span style="color:#b07e00">0</span><span style="color:#000000">);</span>
  <span style="color:#000000">}</span>

<span style="color:#008200">#if defined(DATABASE_MYSQL)</span>
  auto_ptr<span style="color:#000000">&lt;</span>database<span style="color:#000000">&gt;</span> <span style="color:#010181">db</span> <span style="color:#000000">(</span><span style="color:#000000; font-weight:bold">new</span> odb<span style="color:#000000">::</span>mysql<span style="color:#000000">::</span><span style="color:#010181">database</span> <span style="color:#000000">(</span>argc<span style="color:#000000">,</span> argv<span style="color:#000000">));</span>
<span style="color:#008200">#elif defined(DATABASE_SQLITE)</span>
  auto_ptr<span style="color:#000000">&lt;</span>database<span style="color:#000000">&gt;</span> <span style="color:#010181">db</span> <span style="color:#000000">(</span>
    <span style="color:#000000; font-weight:bold">new</span> odb<span style="color:#000000">::</span>sqlite<span style="color:#000000">::</span><span style="color:#010181">database</span> <span style="color:#000000">(</span>
      argc<span style="color:#000000">,</span> argv<span style="color:#000000">,</span> <span style="color:#000000; font-weight:bold">false</span><span style="color:#000000">,</span> SQLITE_OPEN_READWRITE <span style="color:#000000">|</span> SQLITE_OPEN_CREATE<span style="color:#000000">));</span>

  <span style="color:#838183; font-style:italic">// Create the database schema. Due to bugs in SQLite foreign key</span>
  <span style="color:#838183; font-style:italic">// support for DDL statements, we need to temporarily disable</span>
  <span style="color:#838183; font-style:italic">// foreign keys.</span>
  <span style="color:#838183; font-style:italic">//</span>
  <span style="color:#000000">{</span>
    connection_ptr <span style="color:#010181">c</span> <span style="color:#000000">(</span>db<span style="color:#000000">-&gt;</span><span style="color:#010181">connection</span> <span style="color:#000000">());</span>

    c<span style="color:#000000">-&gt;</span><span style="color:#010181">execute</span> <span style="color:#000000">(</span><span style="color:#bf0303">&quot;PRAGMA foreign_keys=OFF&quot;</span><span style="color:#000000">);</span>

    transaction <span style="color:#010181">t</span> <span style="color:#000000">(</span>c<span style="color:#000000">-&gt;</span><span style="color:#010181">begin</span> <span style="color:#000000">());</span>
    schema_catalog<span style="color:#000000">::</span><span style="color:#010181">create_schema</span> <span style="color:#000000">(*</span>db<span style="color:#000000">);</span>
    t<span style="color:#000000">.</span><span style="color:#010181">commit</span> <span style="color:#000000">();</span>

    c<span style="color:#000000">-&gt;</span><span style="color:#010181">execute</span> <span style="color:#000000">(</span><span style="color:#bf0303">&quot;PRAGMA foreign_keys=ON&quot;</span><span style="color:#000000">);</span>
  <span style="color:#000000">}</span>
<span style="color:#008200">#elif defined(DATABASE_PGSQL)</span>
  auto_ptr<span style="color:#000000">&lt;</span>database<span style="color:#000000">&gt;</span> <span style="color:#010181">db</span> <span style="color:#000000">(</span><span style="color:#000000; font-weight:bold">new</span> odb<span style="color:#000000">::</span>pgsql<span style="color:#000000">::</span><span style="color:#010181">database</span> <span style="color:#000000">(</span>argc<span style="color:#000000">,</span> argv<span style="color:#000000">));</span>
<span style="color:#008200">#elif defined(DATABASE_ORACLE)</span>
  auto_ptr<span style="color:#000000">&lt;</span>database<span style="color:#000000">&gt;</span> <span style="color:#010181">db</span> <span style="color:#000000">(</span><span style="color:#000000; font-weight:bold">new</span> odb<span style="color:#000000">::</span>oracle<span style="color:#000000">::</span><span style="color:#010181">database</span> <span style="color:#000000">(</span>argc<span style="color:#000000">,</span> argv<span style="color:#000000">));</span>
<span style="color:#008200">#elif defined(DATABASE_MSSQL)</span>
  auto_ptr<span style="color:#000000">&lt;</span>database<span style="color:#000000">&gt;</span> <span style="color:#010181">db</span> <span style="color:#000000">(</span><span style="color:#000000; font-weight:bold">new</span> odb<span style="color:#000000">::</span>mssql<span style="color:#000000">::</span><span style="color:#010181">database</span> <span style="color:#000000">(</span>argc<span style="color:#000000">,</span> argv<span style="color:#000000">));</span>
<span style="color:#008200">#endif</span>

  <span style="color:#000000; font-weight:bold">return</span> db<span style="color:#000000">;</span>
<span style="color:#000000">}</span>

<span style="color:#008200">#endif</span> <span style="color:#838183; font-style:italic">// DATABASE_HXX</span><span style="color:#008200"></span>
</code></pre></td></tr></table>
</div> <!-- class=content -->
<div class='footer'>generated by <a href='https://git.zx2c4.com/cgit/about/'>cgit v1.1</a> at 2019-10-22 06:58:32 +0000</div>
</div> <!-- id=cgit -->
</body>
</html>
