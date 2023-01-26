import {AfterViewInit, Component, ElementRef, Input, ViewChild} from '@angular/core';
import {Point} from "./point";

@Component({
  selector: 'app-graph',
  styleUrls: ['./graph.component.css'],
  template: `
    <canvas #canvas [width]="1000" [height]="1000"></canvas>
  `
})
export class GraphComponent implements AfterViewInit {
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

  ngOnChanges() {
    this.draw();
  }

  private draw() {
    if (this.ctx) {
      this.ctx.clearRect(0, 0, 10000, 10000);
      if (this.coordinates.length === 0) return;
      if (this.order.length !== 0) {
        this.ctx.beginPath();
        this.ctx.moveTo(this.coordinates[this.order[0]].x * 5, this.coordinates[this.order[0]].y * 5);
        for (let i = 1; i < this.order.length; i++) {
          this.ctx.lineTo(this.coordinates[this.order[i]].x * 5, this.coordinates[this.order[i]].y * 5);
          this.ctx.stroke();
        }
        this.ctx.lineTo(this.coordinates[this.order[0]].x * 5, this.coordinates[this.order[0]].y * 5);
        this.ctx.stroke();
      }
      this.coordinates.forEach((point: Point) => {
          // @ts-ignore
          this.ctx.fillStyle = 'red';
          // @ts-ignore
          this.ctx.lineWidth = 5;
          // @ts-ignore
          this.ctx.beginPath();
          // @ts-ignore
          this.ctx.arc(point.x * 5, point.y * 5, 5, 0, 2 * Math.PI, false);
          // @ts-ignore
          this.ctx.fill();
        }
      );
    }
  }
}
