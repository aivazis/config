<?xml version='1.0'?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version='1.0'>
  <xsl:import href="file://xxxDB2LATEX_XSL_DIRxxx/docbook.xsl"/>
  <!--<xsl:import href="http://db2latex.sourceforge.net/xsl/docbook.xsl"/>-->

  <xsl:param name="l10n.gentext.language" select="'en'"/>

  <xsl:param name="tex.math.in.alt" select="'latex'"/>

  <xsl:param name="use.role.for.mediaobject" select="1"/>

  <!-- match equation:mediaobject:textobject -->
  <xsl:template match="textobject">
    <xsl:choose>
      <xsl:when test="ancestor::equation and (@role='tex' or @role='latex')">
	<xsl:text>\begin{displaymath}</xsl:text>
	<xsl:call-template name="label.id"/>
	<xsl:value-of select="phrase"/>
	<xsl:text>\end{displaymath}&#10;</xsl:text>
      </xsl:when>
    </xsl:choose>
  </xsl:template>


<!--
  <xsl:param name="admon.graphics.path" select="'db2latex-figures'"/>

  <xsl:param name="latex.mapping.xml" select="document('mydb2latex.map.xml')"/>


  <xsl:template match="alt">
    <xsl:choose>
      <xsl:when test="ancestor::inlineequation and (@role='tex' or @role='latex' or $tex.math.in.alt='plain' or $tex.math.in.alt='latex')">
	<xsl:text>\ensuremath{</xsl:text>
	<xsl:value-of select="."/>
	<xsl:text>}</xsl:text>
      </xsl:when>
      <xsl:when test="(ancestor::equation|ancestor::informalequation) and (@role='tex' or @role='latex' or $tex.math.in.alt='plain' or $tex.math.in.alt='latex')">
	<xsl:call-template name="label.id"/>
	<xsl:value-of select="."/>
      </xsl:when>
      <xsl:when test="$tex.math.in.alt='plain' or $tex.math.in.alt='latex'">
	<xsl:value-of select="."/>
      </xsl:when>
      <xsl:otherwise>
	<xsl:apply-templates/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
-->  
</xsl:stylesheet>
