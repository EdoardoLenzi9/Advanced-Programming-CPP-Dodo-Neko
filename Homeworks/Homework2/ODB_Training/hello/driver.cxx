<!DOCTYPE html>
<html lang='en'>
<head>
<title>driver.cxx\hello - odb-examples - ODB examples
</title>
<meta name='generator' content='cgit v1.1'/>
<meta name='robots' content='noindex, nofollow'/>
<link rel='stylesheet' type='text/css' href='/cgit-css/cgit.css'/>
<link rel='shortcut icon' href='/favicon.ico'/>
<link rel='alternate' title='Atom feed' href='https://git.codesynthesis.com/cgit/odb/odb-examples/atom/hello/driver.cxx?h=master' type='application/atom+xml'/>
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
<a href='/cgit/odb/odb-examples/about/'>about</a><a href='/cgit/odb/odb-examples/'>summary</a><a href='/cgit/odb/odb-examples/refs/'>refs</a><a href='/cgit/odb/odb-examples/log/hello/driver.cxx'>log</a><a class='active' href='/cgit/odb/odb-examples/tree/hello/driver.cxx'>tree</a><a href='/cgit/odb/odb-examples/commit/hello/driver.cxx'>commit</a><a href='/cgit/odb/odb-examples/diff/hello/driver.cxx'>diff</a></td><td class='form'><form class='right' method='get' action='/cgit/odb/odb-examples/log/hello/driver.cxx'>
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
<div class='path'>path: <a href='/cgit/odb/odb-examples/tree/'>root</a>/<a href='/cgit/odb/odb-examples/tree/hello'>hello</a>/<a href='/cgit/odb/odb-examples/tree/hello/driver.cxx'>driver.cxx</a></div><div class='content'>blob: 3a4de8c23f7e1957225e362a429ba9331c3b5648 (<a href='/cgit/odb/odb-examples/plain/hello/driver.cxx'>plain</a>)
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
<a id='n95' href='#n95'>95</a>
<a id='n96' href='#n96'>96</a>
<a id='n97' href='#n97'>97</a>
<a id='n98' href='#n98'>98</a>
<a id='n99' href='#n99'>99</a>
<a id='n100' href='#n100'>100</a>
<a id='n101' href='#n101'>101</a>
<a id='n102' href='#n102'>102</a>
<a id='n103' href='#n103'>103</a>
<a id='n104' href='#n104'>104</a>
<a id='n105' href='#n105'>105</a>
<a id='n106' href='#n106'>106</a>
<a id='n107' href='#n107'>107</a>
<a id='n108' href='#n108'>108</a>
<a id='n109' href='#n109'>109</a>
<a id='n110' href='#n110'>110</a>
<a id='n111' href='#n111'>111</a>
<a id='n112' href='#n112'>112</a>
<a id='n113' href='#n113'>113</a>
<a id='n114' href='#n114'>114</a>
<a id='n115' href='#n115'>115</a>
<a id='n116' href='#n116'>116</a>
<a id='n117' href='#n117'>117</a>
<a id='n118' href='#n118'>118</a>
<a id='n119' href='#n119'>119</a>
<a id='n120' href='#n120'>120</a>
<a id='n121' href='#n121'>121</a>
<a id='n122' href='#n122'>122</a>
<a id='n123' href='#n123'>123</a>
<a id='n124' href='#n124'>124</a>
<a id='n125' href='#n125'>125</a>
<a id='n126' href='#n126'>126</a>
<a id='n127' href='#n127'>127</a>
<a id='n128' href='#n128'>128</a>
<a id='n129' href='#n129'>129</a>
<a id='n130' href='#n130'>130</a>
</pre></td>
<td class='lines'><pre><code><span style="color:#838183; font-style:italic">// file      : hello/driver.cxx</span>
<span style="color:#838183; font-style:italic">// copyright : not copyrighted - public domain</span>

<span style="color:#008200">#include &lt;memory&gt;</span>   <span style="color:#838183; font-style:italic">// std::auto_ptr</span>
<span style="color:#008200"></span><span style="color:#008200">#include &lt;iostream&gt;</span>

<span style="color:#008200">#include &lt;odb/database.hxx&gt;</span>
<span style="color:#008200">#include &lt;odb/transaction.hxx&gt;</span>

<span style="color:#008200">#include</span> <span style="color:#818100">&quot;database.hxx&quot;</span><span style="color:#008200"></span> <span style="color:#838183; font-style:italic">// create_database</span>
<span style="color:#008200"></span>
<span style="color:#008200">#include</span> <span style="color:#818100">&quot;person.hxx&quot;</span><span style="color:#008200"></span>
<span style="color:#008200">#include</span> <span style="color:#818100">&quot;person-odb.hxx&quot;</span><span style="color:#008200"></span>

<span style="color:#000000; font-weight:bold">using namespace</span> std<span style="color:#000000">;</span>
<span style="color:#000000; font-weight:bold">using namespace</span> odb<span style="color:#000000">::</span>core<span style="color:#000000">;</span>

<span style="color:#0057ae">int</span>
<span style="color:#010181">main</span> <span style="color:#000000">(</span><span style="color:#0057ae">int</span> argc<span style="color:#000000">,</span> <span style="color:#0057ae">char</span><span style="color:#000000">*</span> argv<span style="color:#000000">[])</span>
<span style="color:#000000">{</span>
  <span style="color:#000000; font-weight:bold">try</span>
  <span style="color:#000000">{</span>
    auto_ptr<span style="color:#000000">&lt;</span>database<span style="color:#000000">&gt;</span> <span style="color:#010181">db</span> <span style="color:#000000">(</span><span style="color:#010181">create_database</span> <span style="color:#000000">(</span>argc<span style="color:#000000">,</span> argv<span style="color:#000000">));</span>

    <span style="color:#0057ae">unsigned long</span> john_id<span style="color:#000000">,</span> joe_id<span style="color:#000000">;</span>

    <span style="color:#838183; font-style:italic">// Create a few persistent person objects.</span>
    <span style="color:#838183; font-style:italic">//</span>
    <span style="color:#000000">{</span>
      person <span style="color:#010181">john</span> <span style="color:#000000">(</span><span style="color:#bf0303">&quot;John&quot;</span><span style="color:#000000">,</span> <span style="color:#bf0303">&quot;Doe&quot;</span><span style="color:#000000">,</span> <span style="color:#b07e00">33</span><span style="color:#000000">);</span>
      person <span style="color:#010181">jane</span> <span style="color:#000000">(</span><span style="color:#bf0303">&quot;Jane&quot;</span><span style="color:#000000">,</span> <span style="color:#bf0303">&quot;Doe&quot;</span><span style="color:#000000">,</span> <span style="color:#b07e00">32</span><span style="color:#000000">);</span>
      person <span style="color:#010181">joe</span> <span style="color:#000000">(</span><span style="color:#bf0303">&quot;Joe&quot;</span><span style="color:#000000">,</span> <span style="color:#bf0303">&quot;Dirt&quot;</span><span style="color:#000000">,</span> <span style="color:#b07e00">30</span><span style="color:#000000">);</span>

      transaction <span style="color:#010181">t</span> <span style="color:#000000">(</span>db<span style="color:#000000">-&gt;</span><span style="color:#010181">begin</span> <span style="color:#000000">());</span>

      <span style="color:#838183; font-style:italic">// Make objects persistent and save their ids for later use.</span>
      <span style="color:#838183; font-style:italic">//</span>
      john_id <span style="color:#000000">=</span> db<span style="color:#000000">-&gt;</span><span style="color:#010181">persist</span> <span style="color:#000000">(</span>john<span style="color:#000000">);</span>
      db<span style="color:#000000">-&gt;</span><span style="color:#010181">persist</span> <span style="color:#000000">(</span>jane<span style="color:#000000">);</span>
      joe_id <span style="color:#000000">=</span> db<span style="color:#000000">-&gt;</span><span style="color:#010181">persist</span> <span style="color:#000000">(</span>joe<span style="color:#000000">);</span>

      t<span style="color:#000000">.</span><span style="color:#010181">commit</span> <span style="color:#000000">();</span>
    <span style="color:#000000">}</span>

    <span style="color:#000000; font-weight:bold">typedef</span> odb<span style="color:#000000">::</span>query<span style="color:#000000">&lt;</span>person<span style="color:#000000">&gt;</span> query<span style="color:#000000">;</span>
    <span style="color:#000000; font-weight:bold">typedef</span> odb<span style="color:#000000">::</span>result<span style="color:#000000">&lt;</span>person<span style="color:#000000">&gt;</span> result<span style="color:#000000">;</span>

    <span style="color:#838183; font-style:italic">// Say hello to those over 30.</span>
    <span style="color:#838183; font-style:italic">//</span>
    <span style="color:#000000">{</span>
      transaction <span style="color:#010181">t</span> <span style="color:#000000">(</span>db<span style="color:#000000">-&gt;</span><span style="color:#010181">begin</span> <span style="color:#000000">());</span>

      result <span style="color:#010181">r</span> <span style="color:#000000">(</span>db<span style="color:#000000">-&gt;</span>query<span style="color:#000000">&lt;</span>person<span style="color:#000000">&gt; (</span>query<span style="color:#000000">::</span>age <span style="color:#000000">&gt;</span> <span style="color:#b07e00">30</span><span style="color:#000000">));</span>

      <span style="color:#000000; font-weight:bold">for</span> <span style="color:#000000">(</span>result<span style="color:#000000">::</span>iterator <span style="color:#010181">i</span> <span style="color:#000000">(</span>r<span style="color:#000000">.</span><span style="color:#010181">begin</span> <span style="color:#000000">());</span> i <span style="color:#000000">!=</span> r<span style="color:#000000">.</span><span style="color:#010181">end</span> <span style="color:#000000">(); ++</span>i<span style="color:#000000">)</span>
      <span style="color:#000000">{</span>
        cout <span style="color:#000000">&lt;&lt;</span> <span style="color:#bf0303">&quot;Hello, &quot;</span> <span style="color:#000000">&lt;&lt;</span> i<span style="color:#000000">-&gt;</span><span style="color:#010181">first</span> <span style="color:#000000">() &lt;&lt;</span> <span style="color:#bf0303">&quot; &quot;</span> <span style="color:#000000">&lt;&lt;</span> i<span style="color:#000000">-&gt;</span><span style="color:#010181">last</span> <span style="color:#000000">() &lt;&lt;</span> <span style="color:#bf0303">&quot;!&quot;</span> <span style="color:#000000">&lt;&lt;</span> endl<span style="color:#000000">;</span>
      <span style="color:#000000">}</span>

      t<span style="color:#000000">.</span><span style="color:#010181">commit</span> <span style="color:#000000">();</span>
    <span style="color:#000000">}</span>

    <span style="color:#838183; font-style:italic">// Joe Dirt just had a birthday, so update his age.</span>
    <span style="color:#838183; font-style:italic">//</span>
    <span style="color:#000000">{</span>
      transaction <span style="color:#010181">t</span> <span style="color:#000000">(</span>db<span style="color:#000000">-&gt;</span><span style="color:#010181">begin</span> <span style="color:#000000">());</span>

      auto_ptr<span style="color:#000000">&lt;</span>person<span style="color:#000000">&gt;</span> <span style="color:#010181">joe</span> <span style="color:#000000">(</span>db<span style="color:#000000">-&gt;</span>load<span style="color:#000000">&lt;</span>person<span style="color:#000000">&gt; (</span>joe_id<span style="color:#000000">));</span>
      joe<span style="color:#000000">-&gt;</span><span style="color:#010181">age</span> <span style="color:#000000">(</span>joe<span style="color:#000000">-&gt;</span><span style="color:#010181">age</span> <span style="color:#000000">() +</span> <span style="color:#b07e00">1</span><span style="color:#000000">);</span>
      db<span style="color:#000000">-&gt;</span><span style="color:#010181">update</span> <span style="color:#000000">(*</span>joe<span style="color:#000000">);</span>

      t<span style="color:#000000">.</span><span style="color:#010181">commit</span> <span style="color:#000000">();</span>
    <span style="color:#000000">}</span>

    <span style="color:#838183; font-style:italic">// Alternative implementation without using the id.</span>
    <span style="color:#838183; font-style:italic">//</span>
    <span style="color:#838183; font-style:italic">/*</span>
<span style="color:#838183; font-style:italic">    {</span>
<span style="color:#838183; font-style:italic">      transaction t (db-&gt;begin ());</span>
<span style="color:#838183; font-style:italic"></span>
<span style="color:#838183; font-style:italic">      // Here we know that there can be only one Joe Dirt in our</span>
<span style="color:#838183; font-style:italic">      // database so we use the query_one() shortcut instead of</span>
<span style="color:#838183; font-style:italic">      // manually iterating over the result returned by query().</span>
<span style="color:#838183; font-style:italic">      //</span>
<span style="color:#838183; font-style:italic">      auto_ptr&lt;person&gt; joe (</span>
<span style="color:#838183; font-style:italic">        db-&gt;query_one&lt;person&gt; (query::first == &quot;Joe&quot; &amp;&amp;</span>
<span style="color:#838183; font-style:italic">                               query::last == &quot;Dirt&quot;));</span>
<span style="color:#838183; font-style:italic"></span>
<span style="color:#838183; font-style:italic">      if (joe.get () != 0)</span>
<span style="color:#838183; font-style:italic">      {</span>
<span style="color:#838183; font-style:italic">        joe-&gt;age (joe-&gt;age () + 1);</span>
<span style="color:#838183; font-style:italic">        db-&gt;update (*joe);</span>
<span style="color:#838183; font-style:italic">      }</span>
<span style="color:#838183; font-style:italic"></span>
<span style="color:#838183; font-style:italic">      t.commit ();</span>
<span style="color:#838183; font-style:italic">    }</span>
<span style="color:#838183; font-style:italic">    */</span>

    <span style="color:#838183; font-style:italic">// Print some statistics about all the people in our database.</span>
    <span style="color:#838183; font-style:italic">//</span>
    <span style="color:#000000">{</span>
      transaction <span style="color:#010181">t</span> <span style="color:#000000">(</span>db<span style="color:#000000">-&gt;</span><span style="color:#010181">begin</span> <span style="color:#000000">());</span>

      <span style="color:#838183; font-style:italic">// The result of this (aggregate) query always has exactly one element</span>
      <span style="color:#838183; font-style:italic">// so use the query_value() shortcut.</span>
      <span style="color:#838183; font-style:italic">//</span>
      person_stat <span style="color:#010181">ps</span> <span style="color:#000000">(</span>db<span style="color:#000000">-&gt;</span>query_value<span style="color:#000000">&lt;</span>person_stat<span style="color:#000000">&gt; ());</span>

      cout <span style="color:#000000">&lt;&lt;</span> endl
           <span style="color:#000000">&lt;&lt;</span> <span style="color:#bf0303">&quot;count  : &quot;</span> <span style="color:#000000">&lt;&lt;</span> ps<span style="color:#000000">.</span>count <span style="color:#000000">&lt;&lt;</span> endl
           <span style="color:#000000">&lt;&lt;</span> <span style="color:#bf0303">&quot;min age: &quot;</span> <span style="color:#000000">&lt;&lt;</span> ps<span style="color:#000000">.</span>min_age <span style="color:#000000">&lt;&lt;</span> endl
           <span style="color:#000000">&lt;&lt;</span> <span style="color:#bf0303">&quot;max age: &quot;</span> <span style="color:#000000">&lt;&lt;</span> ps<span style="color:#000000">.</span>max_age <span style="color:#000000">&lt;&lt;</span> endl<span style="color:#000000">;</span>

      t<span style="color:#000000">.</span><span style="color:#010181">commit</span> <span style="color:#000000">();</span>
    <span style="color:#000000">}</span>

    <span style="color:#838183; font-style:italic">// John Doe is no longer in our database.</span>
    <span style="color:#838183; font-style:italic">//</span>
    <span style="color:#000000">{</span>
      transaction <span style="color:#010181">t</span> <span style="color:#000000">(</span>db<span style="color:#000000">-&gt;</span><span style="color:#010181">begin</span> <span style="color:#000000">());</span>
      db<span style="color:#000000">-&gt;</span>erase<span style="color:#000000">&lt;</span>person<span style="color:#000000">&gt; (</span>john_id<span style="color:#000000">);</span>
      t<span style="color:#000000">.</span><span style="color:#010181">commit</span> <span style="color:#000000">();</span>
    <span style="color:#000000">}</span>
  <span style="color:#000000">}</span>
  <span style="color:#000000; font-weight:bold">catch</span> <span style="color:#000000">(</span><span style="color:#0057ae">const</span> odb<span style="color:#000000">::</span>exception<span style="color:#000000">&amp;</span> e<span style="color:#000000">)</span>
  <span style="color:#000000">{</span>
    cerr <span style="color:#000000">&lt;&lt;</span> e<span style="color:#000000">.</span><span style="color:#010181">what</span> <span style="color:#000000">() &lt;&lt;</span> endl<span style="color:#000000">;</span>
    <span style="color:#000000; font-weight:bold">return</span> <span style="color:#b07e00">1</span><span style="color:#000000">;</span>
  <span style="color:#000000">}</span>
<span style="color:#000000">}</span>
</code></pre></td></tr></table>
</div> <!-- class=content -->
<div class='footer'>generated by <a href='https://git.zx2c4.com/cgit/about/'>cgit v1.1</a> at 2019-10-22 06:58:36 +0000</div>
</div> <!-- id=cgit -->
</body>
</html>
