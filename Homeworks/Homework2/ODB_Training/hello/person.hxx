<!DOCTYPE html>
<html lang='en'>
<head>
<title>person.hxx\hello - odb-examples - ODB examples
</title>
<meta name='generator' content='cgit v1.1'/>
<meta name='robots' content='noindex, nofollow'/>
<link rel='stylesheet' type='text/css' href='/cgit-css/cgit.css'/>
<link rel='shortcut icon' href='/favicon.ico'/>
<link rel='alternate' title='Atom feed' href='https://git.codesynthesis.com/cgit/odb/odb-examples/atom/hello/person.hxx?h=master' type='application/atom+xml'/>
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
<a href='/cgit/odb/odb-examples/about/'>about</a><a href='/cgit/odb/odb-examples/'>summary</a><a href='/cgit/odb/odb-examples/refs/'>refs</a><a href='/cgit/odb/odb-examples/log/hello/person.hxx'>log</a><a class='active' href='/cgit/odb/odb-examples/tree/hello/person.hxx'>tree</a><a href='/cgit/odb/odb-examples/commit/hello/person.hxx'>commit</a><a href='/cgit/odb/odb-examples/diff/hello/person.hxx'>diff</a></td><td class='form'><form class='right' method='get' action='/cgit/odb/odb-examples/log/hello/person.hxx'>
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
<div class='path'>path: <a href='/cgit/odb/odb-examples/tree/'>root</a>/<a href='/cgit/odb/odb-examples/tree/hello'>hello</a>/<a href='/cgit/odb/odb-examples/tree/hello/person.hxx'>person.hxx</a></div><div class='content'>blob: 81a9321e0e1067306cc48c8d3441aa522d0202f7 (<a href='/cgit/odb/odb-examples/plain/hello/person.hxx'>plain</a>)
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
</pre></td>
<td class='lines'><pre><code><span style="color:#838183; font-style:italic">// file      : hello/person.hxx</span>
<span style="color:#838183; font-style:italic">// copyright : not copyrighted - public domain</span>

<span style="color:#008200">#ifndef PERSON_HXX</span>
<span style="color:#008200">#define PERSON_HXX</span>

<span style="color:#008200">#include &lt;string&gt;</span>
<span style="color:#008200">#include &lt;cstddef&gt;</span> <span style="color:#838183; font-style:italic">// std::size_t</span>
<span style="color:#008200"></span>
<span style="color:#008200">#include &lt;odb/core.hxx&gt;</span>

<span style="color:#008200">#pragma db object</span>
<span style="color:#000000; font-weight:bold">class</span> person
<span style="color:#000000">{</span>
<span style="color:#000000; font-weight:bold">public</span><span style="color:#000000">:</span>
  <span style="color:#010181">person</span> <span style="color:#000000">(</span><span style="color:#0057ae">const</span> std<span style="color:#000000">::</span>string<span style="color:#000000">&amp;</span> first<span style="color:#000000">,</span>
          <span style="color:#0057ae">const</span> std<span style="color:#000000">::</span>string<span style="color:#000000">&amp;</span> last<span style="color:#000000">,</span>
          <span style="color:#0057ae">unsigned short</span> age<span style="color:#000000">)</span>
      <span style="color:#000000">:</span> <span style="color:#010181">first_</span> <span style="color:#000000">(</span>first<span style="color:#000000">),</span> <span style="color:#010181">last_</span> <span style="color:#000000">(</span>last<span style="color:#000000">),</span> <span style="color:#010181">age_</span> <span style="color:#000000">(</span>age<span style="color:#000000">)</span>
  <span style="color:#000000">{</span>
  <span style="color:#000000">}</span>

  <span style="color:#0057ae">const</span> std<span style="color:#000000">::</span>string<span style="color:#000000">&amp;</span>
  <span style="color:#010181">first</span> <span style="color:#000000">()</span> <span style="color:#0057ae">const</span>
  <span style="color:#000000">{</span>
    <span style="color:#000000; font-weight:bold">return</span> first_<span style="color:#000000">;</span>
  <span style="color:#000000">}</span>

  <span style="color:#0057ae">const</span> std<span style="color:#000000">::</span>string<span style="color:#000000">&amp;</span>
  <span style="color:#010181">last</span> <span style="color:#000000">()</span> <span style="color:#0057ae">const</span>
  <span style="color:#000000">{</span>
    <span style="color:#000000; font-weight:bold">return</span> last_<span style="color:#000000">;</span>
  <span style="color:#000000">}</span>

  <span style="color:#0057ae">unsigned short</span>
  <span style="color:#010181">age</span> <span style="color:#000000">()</span> <span style="color:#0057ae">const</span>
  <span style="color:#000000">{</span>
    <span style="color:#000000; font-weight:bold">return</span> age_<span style="color:#000000">;</span>
  <span style="color:#000000">}</span>

  <span style="color:#0057ae">void</span>
  <span style="color:#010181">age</span> <span style="color:#000000">(</span><span style="color:#0057ae">unsigned short</span> age<span style="color:#000000">)</span>
  <span style="color:#000000">{</span>
    age_ <span style="color:#000000">=</span> age<span style="color:#000000">;</span>
  <span style="color:#000000">}</span>

<span style="color:#000000; font-weight:bold">private</span><span style="color:#000000">:</span>
  <span style="color:#000000; font-weight:bold">friend class</span> odb<span style="color:#000000">::</span>access<span style="color:#000000">;</span>

  <span style="color:#010181">person</span> <span style="color:#000000">() {}</span>

  <span style="color:#008200">#pragma db id auto</span>
  <span style="color:#0057ae">unsigned long</span> id_<span style="color:#000000">;</span>

  std<span style="color:#000000">::</span>string first_<span style="color:#000000">;</span>
  std<span style="color:#000000">::</span>string last_<span style="color:#000000">;</span>
  <span style="color:#0057ae">unsigned short</span> age_<span style="color:#000000">;</span>
<span style="color:#000000">};</span>

<span style="color:#008200">#pragma db view object(person)</span>
<span style="color:#0057ae">struct</span> person_stat
<span style="color:#000000">{</span>
  <span style="color:#008200">#pragma db column(</span><span style="color:#818100">&quot;count(&quot;</span><span style="color:#008200"> + person::id_ +</span> <span style="color:#818100">&quot;)&quot;</span><span style="color:#008200">)</span>
  std<span style="color:#000000">::</span><span style="color:#0057ae">size_t</span> count<span style="color:#000000">;</span>

  <span style="color:#008200">#pragma db column(</span><span style="color:#818100">&quot;min(&quot;</span><span style="color:#008200"> + person::age_ +</span> <span style="color:#818100">&quot;)&quot;</span><span style="color:#008200">)</span>
  <span style="color:#0057ae">unsigned short</span> min_age<span style="color:#000000">;</span>

  <span style="color:#008200">#pragma db column(</span><span style="color:#818100">&quot;max(&quot;</span><span style="color:#008200"> + person::age_ +</span> <span style="color:#818100">&quot;)&quot;</span><span style="color:#008200">)</span>
  <span style="color:#0057ae">unsigned short</span> max_age<span style="color:#000000">;</span>
<span style="color:#000000">};</span>

<span style="color:#008200">#endif</span> <span style="color:#838183; font-style:italic">// PERSON_HXX</span><span style="color:#008200"></span>
</code></pre></td></tr></table>
</div> <!-- class=content -->
<div class='footer'>generated by <a href='https://git.zx2c4.com/cgit/about/'>cgit v1.1</a> at 2019-10-22 06:58:44 +0000</div>
</div> <!-- id=cgit -->
</body>
</html>
