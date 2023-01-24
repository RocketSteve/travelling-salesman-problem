import {Component, ElementRef, Input, ViewChild} from '@angular/core';
import {Point} from "./point";

@Component({
  selector: 'app-graph',
  template: `
    <canvas #canvas></canvas>
  `
})
export class GraphComponent {
  @ViewChild('canvas') canvas!: ElementRef<HTMLCanvasElement>;
  @Input()
  coordinates: Point[] = [];
  @Input()
  order: number[] = [];
  private ctx!: CanvasRenderingContext2D | null;

  ngAfterViewInit() {
    this.ctx = this.canvas.nativeElement.getContext('2d');
    this.draw();
  }

  private draw() {
    if (this.ctx) {
      this.ctx.beginPath();
      this.ctx.moveTo(this.coordinates[this.order[0]].x, this.coordinates[this.order[0]].y);
      for (let i = 1; i < this.order.length; i++) {
        this.ctx.lineTo(this.coordinates[this.order[i]].x, this.coordinates[this.order[i]].y);
      }
      this.ctx.stroke();
    }
  }
}
