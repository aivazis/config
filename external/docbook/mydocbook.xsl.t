<?xml version='1.0'?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version='1.0'>
  <xsl:import href="file://xxxDB2HTML_XSL_DIRxxx/chunk.xsl"/>

  <xsl:param name="callout.graphics" select="0"/>

  <xsl:param name="chunker.output.encoding" select="'UTF-8'"/>
  <xsl:param name="html.stylesheet" select="'corpstyle.css'"/>
  
  <xsl:param name="chunker.output.indent" select="'yes'"/>

  <xsl:param name="tex.math.in.alt" select="'latex'"/>
  <xsl:param name="passivetex.extensions" select="1"/>

</xsl:stylesheet>
